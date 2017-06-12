#include "Grammatica.h"
#include "Automata.h"
#include <sstream>      // std::ostringstream
#include <iterator>
#include <algorithm>

template<class T>
Grammatica<T>::Grammatica(vector<T> states, vector<char> alphabet, vector<Transition<T>> transitions, vector<T> startStates)
{
	Grammatica<T>::states = states;
	Grammatica<T>::alphabet = alphabet;
	Grammatica<T>::transitions = transitions;
	Grammatica<T>::startStates = startStates;
}

template<class T>
void Grammatica<T>::printGrammatica()
{
	ostringstream N,E,S;
	
	if (!states.empty())
	{
		copy(states.begin(), states.end() - 1, ostream_iterator<string>(N, ","));
		N << states.back();
	}
	
	
	if (!alphabet.empty())
	{
		copy(alphabet.begin(), alphabet.end() - 1, ostream_iterator<char>(E, ","));
		E << alphabet.back();
	}
	if (!startStates.empty())
	{
		copy(startStates.begin(), startStates.end() - 1, ostream_iterator<string>(S, ","));
		S << startStates.back();
	}
	
	cout << endl;
	cout << "Grammatica Representatie" <<endl;
	//G(N,E,P,S)
	cout << "G({" << N.str() << "}, {" << E.str() << "}, &, {" << S.str() << "})" << endl;
	cout << "&:" << endl;
	
	vector<string> Itstates;
	for (string state : states)
	{
		if (find(Itstates.begin(), Itstates.end(), state) != Itstates.end())
		{
		}
		else
		{
			vector<Transition<string>> t = getToStates(state);
			Itstates.push_back(state);
			cout << state << " -> ";
			for (Transition<T> trans : t)
			{
				cout << trans.getSymbol() << trans.getToState() << "|";
			}
			cout << endl;
		}
	}
}

template <class T>
vector<Transition<T>> Grammatica<T>::getToStates(T from)
{
	vector<Transition<T>> toTransitions = {};
	for (Transition<T> &transition : transitions)
	{
		if (from == transition.getFromState())
		{
			toTransitions.push_back(transition);
		}
	}
	return toTransitions;
}

template class Grammatica<string>;