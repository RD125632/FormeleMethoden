#include "Automata.h"

#include <algorithm>

template <class T>
Automata<T>::Automata(std::vector<char> s)
{
	setAlphabet(s);
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
		graphViz.append(state);
	
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
				return isDFA;
		}
	}

	return isDFA;
}

template <class T>
std::vector<Transition<T>> Automata<T>::getToStates(T from, char symbol)
{
	std::vector<Transition<T>> toTransitions = {};
	for(Transition<T> &transition : transitions)
	{
		if (from == transition.getFromState() && symbol == transition.getSymbol())
		{
			toTransitions.push_back(transition);
		}
	}
	return toTransitions;
}


template class Automata<string>;