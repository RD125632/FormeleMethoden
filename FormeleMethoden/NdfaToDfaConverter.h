#pragma once
#include <vector>
#include <set>
#include <string>

#include "Automata.h"

using namespace std;

class NdfaToDfaConverter {
public:
	static Automata<string> Convert(Automata<string> ndfa);
	static Automata<string> Reverse(Automata<string> automaat);
	static Automata<string> OptimizeDfa(Automata<string> dfa);
private:
	static Automata<string> finaliseConversion(Automata<string> merged);
	static void RetrieveEpsilonIncludedState(string state, Automata<string> automata, vector<string>& subStateList);
	static bool CheckExistingRouteForChar(string currentState, char symbol, Automata<string> dfa);
	static int CheckAvailableRoutes(vector<string> states, char symbol, Automata<string> ndfa);
	static bool GenerateToState(string& toState, vector<string> states, char symbol, Automata<string> ndfa);
	static void ConvertState(string currentState, Automata<string>& dfa, Automata<string>& ndfa);
};