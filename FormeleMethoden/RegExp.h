#pragma once
#include <string>
#include <set>

using namespace std;

class RegExp {
public:
	// De mogelijke operatoren voor een reguliere expressie (+, *, |, .) 
	// Daarnaast ook een operator definitie voor 1 keer repeteren (default)
	enum RegOperator { PLUS, STAR, OR, DOT, ONE };

	RegExp();
	RegExp(string p);
	~RegExp();
	RegExp* plus();
	RegExp* star();
	RegExp* or(RegExp *e2);
	RegExp* dot(RegExp *e2);
	set<string> getLanguage(int maxSteps);
	RegOperator getRegOperator();
	string getTerminals();
	RegExp* getLeft();
	RegExp* getRight();
	string toString();

private:
	RegOperator regOperator;
	string terminals;
	RegExp* left;
	RegExp* right;
};