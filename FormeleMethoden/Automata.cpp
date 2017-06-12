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
		for (char c : symbols)
		{
			if (c == word.at(i))
			{
				addTransition(Transition<string>(to_string(i), word.at(i), to_string(i + 1)));
			}
			else
			{
				addTransition(backTrackForRoute(word, i, c));
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
void Automata<T>::EndWith(string word)
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
				addTransition(backTrackForRoute(word, i, c));
			}
		}
	}

	// only on start state in a dfa:
	defineAsStartState(to_string(0));

	// final state:
	defineAsFinalState(to_string(word.length()));
}

template <class T>
void Automata<T>::SwitchDenail()
{
	vector<T> newFinals;
	for (T state : states)
	{
		if (find(finalStates.begin(), finalStates.end(), state) != finalStates.end()) {}
		else
			newFinals.push_back(state);
	}
	finalStates = newFinals;
}


template <class T>
Transition<T> Automata<T>::backTrackForRoute(string word, int index,  char toUse)
{
	// New word with wrong letter
	string checkString = word.substr(0, index);
	string tempString = word.substr(0, index) + toUse;

	while (tempString.length() > 0 && checkString.compare(tempString))
	{
		checkString = checkString.substr(0, tempString.length()-1);
		tempString = tempString.substr(1, tempString.length());
	}
	return Transition<T>(to_string(index), toUse, to_string(tempString.length()));
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
vector<Transition<T>> Automata<T>::getTransitions()
{
	return transitions;
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
	states.push_back(t);
	startStates.push_back(t);
}

template <class T>
void Automata<T>::defineAsFinalState(T t)
{
	states.push_back(t);
	finalStates.push_back(t);
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
vector<Transition<T>> Automata<T>::getToStates(T from, char symbol)
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