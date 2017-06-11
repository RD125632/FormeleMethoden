#pragma once
#include <string>
#include <set>
#include "automata.h"
#include "RegExp.h"

using namespace std;

class Thompson {
public:
	// De mogelijke operatoren voor een reguliere expressie (+, *, |, .) 
	// Daarnaast ook een operator definitie voor 1 keer repeteren (default)
	enum RegOperator { PLUS, STAR, OR, DOT, ONE };

	//Thompson();
	//Thompson(string p);
	//~Thompson();
	//RegExp* plus();
	//RegExp* star();
	//RegExp* or (RegExp *e2);
	//RegExp* dot(RegExp *e2);
	//set<string> getLanguage(int maxSteps);
	static Automata<string>* createAutomata(RegExp* reg);
	static void plusOperator(RegExp* reg, Automata<string>* automata, int counter, string leftState, string rightState);
	static void starOperator(RegExp* reg, Automata<string>* automata, int counter, string leftState, string rightState);
	static void orOperator(RegExp* reg, Automata<string>* automata, int counter, string leftState, string rightState);
	static void dotOperator(RegExp* reg, Automata<string>* automata, int counter, string leftState, string rightState);
	static void oneOperator(RegExp* reg, Automata<string>* automata, int counter, string leftState, string rightState);

private:
	static void thompsonSwitch(RegExp* reg, Automata<string>* automata, int counter, string leftState, string rightState);
	//RegOperator regOperator;
	//string terminals;
	//RegExp* left;
	//RegExp* right;
};