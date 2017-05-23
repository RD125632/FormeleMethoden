#include "Transition.h"
#include <sstream>

template<class T>
Transition<T>::Transition(T fromOrTo, char s) : Transition(fromOrTo, s, fromOrTo)
{
}

template<class T>
Transition<T>::Transition(T from, T to) : Transition(from, EPSILON, to)
{
}

template<class T>
Transition<T>::Transition(T from, char s, T to)
{
	fromState = from;
	toState = to;
	symbol = s;
}

template<class T>
int Transition<T>::compareTo(const Transition<T> &t)
{
	bool fromCmp = fromState == t.fromState;
	bool symbolCmp = symbol == t.symbol;
	bool toCmp = toState == t.toState;

	if (fromCmp)
		return 1;
	else if(symbolCmp)
		return 1;
	else
		return 0;
}

template<class T>
T Transition<T>::getFromState()
{
	return fromState;
}

template<class T>
T Transition<T>::getToState()
{
	return toState;
}

template<class T>
char Transition<T>::getSymbol()
{
	return symbol;
}


template<class T>
string Transition<T>::toString()
{
	std::stringstream ss;
	ss << "(" << getFromState() << "," << getSymbol() << ")" << "-->" << getToState();
	return ss.str();
}

template<class T>
string Transition<T>::toGraphViz()
{
	std::stringstream ss;
	ss << getFromState() << "\t->\t" << getToState() << "\t[label=\"" << getSymbol() << "\"];";
	return ss.str();
}

template class Transition<string>;
