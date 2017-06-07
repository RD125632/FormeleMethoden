#pragma once
#include <vector>
#include <iostream>
#include "Transition.h"


using namespace std;

template <class T>
class Automata {
public:
	Automata(vector<char> s = vector<char>());
	vector<char> getAlphabet();
	vector<T> getStates();
	vector<T> getStartStates();
	vector<T> getFinalStates();
	vector<Transition<T>> getTransitions();

	void addTransition(Transition<T> t);
	void defineAsStartState(T t);
	void defineAsFinalState(T t);
	void printTransitions();
	bool accept(string s);
	bool isDFA();

private:
	vector<Transition<T>> transitions = {};
	vector<char> symbols = {};
	vector<T> states = {};
	vector<T> startStates = {};
	vector<T> finalStates = {};

	void setAlphabet(vector<char> s);
	vector<Transition<T>> getToStates(T from, char symbol);
	T GoTo(char character, T currentState);
};
