#pragma once
#include <vector>
#include <iostream>
#include "Transition.h"


using namespace std;

template <class T>
class Automata {
public:
	Automata(std::vector<char> s = std::vector<char>());
	std::vector<char> getAlphabet();
	void setAlphabet(std::vector<char>);
	void addTransition(Transition<T> t);
	void defineAsStartState(T t);
	void defineAsFinalState(T t);
	void printTransitions();
	bool accept(string s);
	bool isDFA();

private:
	std::vector<Transition<T>> transitions = {};
	std::vector<char> symbols = {};
	std::vector<T> states = {};
	std::vector<T> startStates = {};
	std::vector<T> finalStates = {};

	//void setAlphabet(std::vector<char> s);
	std::vector<Transition<T>> getToStates(T from, char symbol);
	T GoTo(char character, T currentState);
};
