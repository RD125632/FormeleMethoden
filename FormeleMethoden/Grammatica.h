#pragma once
#include <vector>
#include <iostream>

#include "Transition.h"

using namespace std;

template <class T>
class Grammatica {
public:
	Grammatica(vector<T>, vector<char>, vector<Transition<T>>, vector<T>);
	Automata<T> toNFA();
private:
	vector<T> states = {};
	vector<char> alphabet = {};
	vector<Transition<T>> transitions = {};
	vector<T> startStates = {};
};

