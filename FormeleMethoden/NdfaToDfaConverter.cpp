#include "NdfaToDfaConverter.h"
#include <algorithm>

Automata<string> NdfaToDfaConverter::Convert(Automata<string> ndfa)
{
	Automata<string> dfa = Automata<string>(Automata<string>::Preset::none, ndfa.getAlphabet());
	string combinedStartState = "";
	//SortedSet<string> completeStartState = SortedSet<string>();
	vector<string> completeStartState = vector<string>();

	bool isFinalState = false;
	// Loop through all the available start states from the ndfa and create a list with them + their epsilon-linked states
	for(string startState : ndfa.getStartStates())
	{
		RetrieveEpsilonIncludedState(startState, ndfa, completeStartState);
	}

	//Turn sortedset into a string with all its states
	for(string s : completeStartState)
	{
		combinedStartState += s + "_";
		vector<string> tempFinalStatesContainer = ndfa.getFinalStates();
		if (std::find(tempFinalStatesContainer.begin(), tempFinalStatesContainer.end(), s) != tempFinalStatesContainer.end())
			isFinalState = true;
	}

	//trim last "_" off of string
	if (combinedStartState.back() = '_')
		combinedStartState = combinedStartState.erase(combinedStartState.length() - 1);

	//Start conversion
	ConvertState(combinedStartState, dfa, ndfa);
	// Define combinedStartState as one and only start state in dfa
	dfa.defineAsStartState(combinedStartState);
	if (isFinalState)
		dfa.defineAsFinalState(combinedStartState);

	// Add a symbol loop to the failstate if one is created during conversion.
	vector<string> tempStatesContainer = dfa.getStates();
	if (std::find(tempStatesContainer.begin(), tempStatesContainer.end(), "F") != tempStatesContainer.end()) {
		for (char route : dfa.getAlphabet())
		{
			dfa.addTransition(Transition<string>("F", route, "F"));
		}
	}
	return finaliseConversion(dfa);
}

Automata<string> NdfaToDfaConverter::Reverse(Automata<string> automaat)
{
	Automata<string> reverseAutomaat = Automata<string>(Automata<string>::Preset::none, automaat.getAlphabet());
	for(Transition<string> transition : automaat.getTransitions())
	{
		reverseAutomaat.addTransition(Transition<string>(transition.getToState(), transition.getSymbol(), transition.getFromState()));
	}
	reverseAutomaat.setStartStates(automaat.getFinalStates());
	reverseAutomaat.setFinalStates(automaat.getStartStates());
	return reverseAutomaat;
}

Automata<string> NdfaToDfaConverter::OptimizeDfa(Automata<string> dfa)
{
	return Convert(Reverse(Convert(Reverse(dfa))));
}

Automata<string> NdfaToDfaConverter::finaliseConversion(Automata<string> merged)
{
	Automata<string> finalisedMerge = Automata<string>(Automata<string>::Preset::none, merged.getAlphabet());

	for(Transition<string> t : merged.getTransitions())
	{
		finalisedMerge.addTransition(Transition<string>(t.getFromState().Replace("_", string.Empty), t.Symbol, t.ToState.Replace("_", string.Empty)));
	}

	for(string startState : merged.getStartStates())
	{
		finalisedMerge.defineAsStartState(startState.Replace("_", string.Empty));
	}

	for(string finalState : merged.getFinalStates())
	{
		finalisedMerge.defineAsFinalState(finalState.Replace("_", string.Empty));
	}


	return finalisedMerge;
}

void NdfaToDfaConverter::RetrieveEpsilonIncludedState(string state, Automata<string> automata, vector<string>& subStateList)
{
	//Add given state to the given substatelist
	subStateList.push_back(state);

	//retrieve the list of transitions from the given state
	vector<Transition<string>> trans = automata.getTransition(state);

	//Loop through all the transitions in search of epsilon routes. If an epsilon route is found that is not yet included in the list the route and its subsequent epsilon routes-
	//will be added to substatelist through recursion.
	for(Transition<string> t : trans)
	{
		//std::find(tempStatesContainer.begin(), tempStatesContainer.end(), "F") != tempStatesContainer.end()
		//!subStateList.Contains(t.ToState
		if (t.getSymbol() == '$')
		{
			if (std::find(subStateList.begin(), subStateList.end(), t.getToState()) != subStateList.end()) {
				//do nothing
			}
			else {
				RetrieveEpsilonIncludedState(t.getToState(), automata, subStateList);
			}
			
		}
	}
}

bool NdfaToDfaConverter::CheckExistingRouteForChar(string currentState, char symbol, Automata<string> dfa)
{
	vector<Transition<string>> currentTrans = dfa.getTransition(currentState);
	for(Transition<string> t : currentTrans)
	{
		if (t.getSymbol() == symbol)
		{
			return true;
		}
	}
	return false;
}

int NdfaToDfaConverter::CheckAvailableRoutes(vector<string> states, char symbol, Automata<string> ndfa)
{
	//array which shows how many possible routes there are for each sub-state
	int[] possibleRoutesPerState = new int[states.Length];
	//// value that shows the amount of routes the ndfa has for all the substates combined.
	int correctAmountOfRoutes = 0;

	//reads ndfa for possible routes, saves maximum amount of accessible routes to correctAmountOfRoutes
	for(string state : states)
	{
		if (ndfa.getTransition(state).Count(transition = > transition.Symbol == symbol) > correctAmountOfRoutes)
		{
			correctAmountOfRoutes = ndfa.GetTransition(state).Count(transition = > transition.Symbol == symbol);
		}
	}
	return correctAmountOfRoutes;
}

bool NdfaToDfaConverter::GenerateToState(string & toState, vector<string> states, char symbol, Automata<string> ndfa)
{
	//boolean that will save whether this new TOSTATE needs to be a finalstate
	bool isFinalState = false;
	//Set of all the substates that need to be combined. this set does also include all states reached through epsilon routes
	SortedSet<string> newStates = new SortedSet<string>();

	//Loop through all the substates 
	for(string state : states)
	{
		//ndfa transitions for state
		List<Transition<string>> trans = ndfa.getTransition(state);

		//This loop goes through all the aforementioned transitions
		//to see if there are routes with the correct symbol that need to be added to the new TOSTATE
		for(Transition<string> t : trans)
		{
			if (t.getSymbol() == symbol)
			{
				RetrieveEpsilonIncludedState(t.getToState(), ndfa, newStates);

				//DEPRECATED, does not work if finalstate is reached through epsilon routes
				//Check if this state is final, if one of the substates for the new TOSTATE is final, TOSTATE becomes final as a whole.
				//if (ndfa.FinalStates.Contains(t.ToState))
				//{
				//    isFinalState = true;
				//}
			}
		}
	}

	//combines substates into one string (TOSTATE)
	for(string subState : newStates)
	{
		toState += subState + "_";
		if (ndfa.getFinalStates().Contains(subState))
			isFinalState = true;
	}
	toState = toState.TrimEnd('_');
	return isFinalState;
}

void NdfaToDfaConverter::ConvertState(string currentState, Automata<string>& dfa, Automata<string>& ndfa)
{
	//If this state is already completely processed, return to avoid stackoverflow exception
	if (dfa.getTransition(currentState).Count == ndfa.getAlphabet().Count)
		return;

	//split given state for comparison
	string[] states = currentState.Split('_');

	//Loop through all symbols aka all the necessary routes
	for(char symbol : ndfa.getAlphabet())
	{
		//checks if this symbol already has a route in the new DFA
		if (CheckExistingRouteForChar(currentState, symbol, dfa))
			return;

		int correctAmountOfRoutes = CheckAvailableRoutes(states, symbol, ndfa);

		//the TOSTATE of the to be added implementation
		string toState = "";
		if (correctAmountOfRoutes == 0)
		{
			dfa.addTransition(Transition<string>(currentState, symbol, "F"));
		}
		else
		{
			bool isFinalState = GenerateToState(toState, states, symbol, ndfa);

			dfa.addTransition(Transition<string>(currentState, symbol, toState));

			//Checks if currentState is should be final aswell (could be done better)
			if (ndfa.getFinalStates().Contains(currentState))
			{
				dfa.defineAsFinalState(currentState);
			}

			if (isFinalState)
				dfa.defineAsFinalState(toState);

			//checks if its not a loop to itself
			if (currentState != toState)
				ConvertState(toState, dfa, ndfa);
		}
	}
}
