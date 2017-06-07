#include "Grammatica.h"
#include "Automata.h"


template<class T>
Grammatica<T>::Grammatica(vector<T> states, vector<char> alphabet, vector<Transition<T>> transitions, vector<T> startStates)
{
	Grammatica<T>::states = states;
	Grammatica<T>::alphabet = alphabet;
	Grammatica<T>::transitions = transitions;
	Grammatica<T>::startStates = startStates;
}

template<class T>
Automata<T> Grammatica<T>::toNFA()
{
	Automata<string> m = Automata<string>(Grammatica<T>::alphabet);

	return m;
}

template class Grammatica<string>;