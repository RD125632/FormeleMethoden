#pragma once
#include <vector>
#include <set>
#include <string>

#include "RegExp.h"
#include "Grammatica.h"

using namespace std;

class Tests {
public:
	Tests();
	void PracticumL1R1();
	void PracticumL1R2();
	void PracticumL1R3();
	void PracticumL1R4();
	void RegExpessie();

	bool AcceptWord(set<char>, string);
	void InputWord();

	void InputGrammer();
	void GrammaticaToNfa(Grammatica<string>*);

	void InputNFA();
	void NfaToGrammatica(Automata<string>* automata);

	RegExp* RegExBreakdown(string);
	void InputWithRegEx();

	void GetLanguageFromRegEx();
	void printLanguageAsString(set<string>);
};