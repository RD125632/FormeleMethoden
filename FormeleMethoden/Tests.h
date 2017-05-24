#pragma once
#include <vector>
#include <set>
#include <string>

#include "RegExp.h"

using namespace std;

class Tests {
public:
	Tests();
	void PracticumL1R1();
	void PracticumL1R2();
	void PracticumL1R3();
	void PracticumL1R4();

	bool AcceptWord(set<char>, string);
	void InputWithGrammer();

	RegExp* RegExBreakdown(string);
	void InputWithRegEx();

	void GetLanguageFromRegEx();
	void printLanguageAsString(set<string>);
};