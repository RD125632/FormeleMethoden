#pragma once
#include <vector>
#include <set>
#include <string>

#include "Automata.h"
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
	void Thompson();
	void printThompson(RegExp* reg);
	void GenerateWord(string, string, Automata<string>*);
	void TryWords();
	bool AcceptWord(set<char>, string);
	void InputWord();
	void Tests::DFABegin();
	void InputGrammer();
	void NFA1();
	void NFA2();
	void NFA3();
	void GrammaticaToNfa(Grammatica<string>*);
	void InputNFA();
	void NfaToGrammatica(Automata<string>* automata);
	RegExp* RegExBreakdown(string);
	void InputWithRegEx();
	void InputWithRegEx(string regex);

	void GetLanguageFromRegEx1();
	void GetLanguageFromRegEx2();
	void GetLanguageFromRegEx3();
	void printLanguageAsString(set<string>);
	void readRegExpFromFile();
	void saveResultsToFile(string);
};