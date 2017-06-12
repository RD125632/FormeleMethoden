#pragma once
#include <vector>
#include <iostream>
#include "Transition.h"
#include <set>

using namespace std;

template <class T>
class Automata {
public:
	// Preset DFA types
	enum Preset { beginWith, endWith, contains, none } preset;

	Automata(Preset p = Preset::none,vector<char> s = vector<char>());
	Automata(string str, Preset p = Preset::none, vector<char> s = vector<char>());
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
	void setAlphabet(vector<char> s);
private:
	void Automata<T>::BeginWith(string word);
	void Automata<T>::EndWith(string word);
	void Automata<T>::Contains(string word);
	vector<Transition<T>> transitions = {};
	vector<char> symbols = {};
	vector<T> states = {};
	vector<T> startStates = {};
	vector<T> finalStates = {};
	vector<Transition<T>> getToStates(T from, char symbol);
	T GoTo(char character, T currentState);
};
