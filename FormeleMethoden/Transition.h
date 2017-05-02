#pragma once
#include <string>

using namespace std;

template <class T>
class Transition {
public:
	static const char EPSILON = '$';

	Transition(T fromOrTo, char s);
	Transition(T from, T to);
	Transition(T from, char s, T to);
	bool equals(const T &other);
	int compareTo(const Transition<T> &t);
	T getFromState();
	T getToState();
	char getSymbol();
	string toString();
	string Transition<T>::toGraphViz();

private:
	T fromState;
	T toState;
	char symbol;
};
