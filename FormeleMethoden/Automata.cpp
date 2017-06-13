#include "Automata.h"
#include "Grammatica.h"

#include <algorithm>

template <class T>
Automata<T>::Automata(Preset preset, vector<char> s)
{
	setAlphabet(s);
}

template<class T>
Automata<T>::Automata(string str, Preset p, vector<char> s)
{
	setAlphabet(s);
	switch (p)
	{
	case Preset::none:
		break;
	case Preset::beginWith:
		BeginWith(str);
		break;
	case Preset::contains:
		Contains(str);
		break;
	case Preset::endWith:
		EndWith(str);
		break;
	}
}

template <class T>
void Automata<T>::BeginWith(string word)
{	
	for (int i = 0; i < word.length(); i++)
	{
		for (char c : symbols)
		{
			if (c == word.at(i))
			{
				addTransition(Transition<string>(to_string(i), word.at(i), to_string(i + 1)));
			}
			else
			{
				addTransition(Transition<string>(to_string(i), c, "F"));
			}
		}
	}

	for (char c : symbols)
	{
		addTransition(Transition<string>(to_string(word.length()), c, to_string(word.length())));
	}

	// only on start state in a dfa:
	defineAsStartState(to_string(0));

	// final state:
	defineAsFinalState(to_string(word.length()));
}

template <class T>
void Automata<T>::Contains(string word)
{
	for (int i = 0; i < word.length(); i++)
	{
		addTransition(Transition<string>(to_string(i), word.at(i), to_string(i + 1)));
	}

	for (char c : symbols)
	{
		addTransition(Transition<string>(to_string(word.length()), c, to_string(word.length())));
	}

	// only on start state in a dfa:
	defineAsStartState(to_string(0));

	// final state:
	defineAsFinalState(to_string(word.length()));
}

template <class T>
void Automata<T>::EndWith(string word)
{
	for (int i = 0; i < word.length(); i++)
	{
		addTransition(Transition<string>(to_string(i), word.at(i), to_string(i + 1)));
	}

	for (char c : symbols)
	{
		addTransition(Transition<string>(to_string(word.length()), c, to_string(word.length())));
	}

	// only on start state in a dfa:
	defineAsStartState(to_string(0));

	// final state:
	defineAsFinalState(to_string(word.length()));
}

template <class T>
void Automata<T>::setAlphabet(std::vector<char> s)
{
	symbols = s;
	symbols.erase(std::unique(symbols.begin(), symbols.end()), symbols.end());
}

template <class T>
std::vector<char> Automata<T>::getAlphabet()
{
	return symbols;
}

template<class T>
vector<T> Automata<T>::getStates()
{
	return states;
}

template<class T>
vector<T> Automata<T>::getStartStates()
{
	return startStates;
}

template<class T>
vector<T> Automata<T>::getFinalStates()
{
	return finalStates;
}

template<class T>
void Automata<T>::setStartStates(vector<T> startStates)
{
	Automata<T>::startStates = startStates;
}

template<class T>
void Automata<T>::setFinalStates(vector<T> finalStates)
{
	Automata<T>::finalStates = finalStates;
}

template<class T>
vector<Transition<T>> Automata<T>::getTransitions()
{
	return transitions;
}

template<class T>
vector<Transition<T>> Automata<T>::getTransition(T state)
{
	vector<Transition<T>> conversieTrans, epsilonTrans;
	for (char c : getAlphabet())
	{
		for (Transition<T> t : getToStates(state, c))
		{
			conversieTrans.push_back(t);
			if (t.getSymbol() == t.EPSILON)
			{
				epsilonTrans.push_back(t);
			}
		}
	}

	for (Transition<T> epsilon : epsilonTrans)
	{
		vector<Transition<T>> tempEpsilon = getTransition(epsilon.getToState());
		conversieTrans.insert(conversieTrans.end(), tempEpsilon.begin(), tempEpsilon.end());
	}

	return conversieTrans;
}

template <class T>
void Automata<T>::addTransition(Transition<T> t)
{
	transitions.push_back(t);
	states.push_back(t.getToState());
	states.push_back(t.getFromState());
}

template <class T>
void Automata<T>::defineAsStartState(T t)
{
	if (std::find(startStates.begin(), startStates.end(), t) != startStates.end()) {
		//do nothing, t is already a startstate
	}
	else {
		states.push_back(t);
		startStates.push_back(t);
	}
}

template <class T>
void Automata<T>::defineAsFinalState(T t)
{
	if (std::find(finalStates.begin(), finalStates.end(), t) != finalStates.end()) {
		//do nothing, t is already a finalState
	}
	else {
		states.push_back(t);
		finalStates.push_back(t);
	}
}

template <class T>
void Automata<T>::printTransitions()
{
	string graphViz = "";
	graphViz.append("digraph finite_state_machine {\n");
	graphViz.append("\trankdir=LR;\n");
	graphViz.append("\tnode[shape = doublecircle];");

	for (T state : finalStates)
	{
		graphViz.append(" ");
		graphViz.append(state);
	}

	graphViz.append(";\n");

	graphViz.append("\tnode[shape = circle];\n");
	for (Transition<T> &t : transitions)
	{
		graphViz.append("\t\t");
		graphViz.append(t.toGraphViz());
		graphViz.append("\n");
	}

	graphViz.append("}");

	cout << graphViz << endl;
	cout << endl;
}

template <class T>
bool Automata<T>::isDFA()
{
	bool isDFA = true;

	for (string from : states)
	{
		for (char symbol : symbols)
		{
			isDFA = isDFA && getToStates(from, symbol).size() == 1;
			if (!isDFA)
				return false;
		}
	}

	return isDFA;
}

template <class T>
std::vector<Transition<T>> Automata<T>::getToStates(T from, char symbol)
{
	std::vector<Transition<T>> toTransitions = {};
	for (Transition<T> &transition : transitions)
	{
		if (from == transition.getFromState() && symbol == transition.getSymbol())
		{
			toTransitions.push_back(transition);
		}
	}
	return toTransitions;
}

template <class T>
bool Automata<T>::accept(string s)
{
	T currentState = startStates.front();
	for (char& character : s)
	{
		currentState = GoTo(character, currentState);
		for (T finalState : finalStates)
		{
			if (currentState == finalState)
				return true;
		}
	}
	return false;
}

template <class T>
T Automata<T>::GoTo(char character, T currentState)
{
	for (Transition<T> transition : transitions)
	{
		if (transition.getFromState() == currentState && transition.getSymbol() == character)
		{
			return transition.getToState();
		}
	}

	return currentState;
}

template class Automata<string>;