#include <stdio.h>
#include <vector>
#include <set>
#include <string>
#include <windows.h>   // WinApi header

#include "Automata.h"
#include "Transition.h"
#include "RegExp.h"

using namespace std;

void PracticumL1R1()
{
	// Begint met 'ABB' of eindigt op BAAB
	std::vector<char> alphabet = { 'a', 'b' };
	Automata<string> m = Automata<string>(alphabet);

	m.addTransition(Transition<string>("S", alphabet[0], "2"));
	m.addTransition(Transition<string>("S", alphabet[1], "5"));

	m.addTransition(Transition<string>("2", alphabet[0], "9"));
	m.addTransition(Transition<string>("2", alphabet[1], "3"));

	m.addTransition(Transition<string>("3", alphabet[0], "6"));
	m.addTransition(Transition<string>("3", alphabet[1], "4"));
	
	m.addTransition(Transition<string>("4", alphabet[0], "4"));
	m.addTransition(Transition<string>("4", alphabet[1], "4"));
	
	m.addTransition(Transition<string>("5", alphabet[0], "6"));
	m.addTransition(Transition<string>("5", alphabet[1], "5"));

	m.addTransition(Transition<string>("6", alphabet[0], "7"));
	m.addTransition(Transition<string>("6", alphabet[1], "5"));

	m.addTransition(Transition<string>("7", alphabet[0], "9"));
	m.addTransition(Transition<string>("7", alphabet[1], "8"));

	m.addTransition(Transition<string>("8", alphabet[0], "6"));
	m.addTransition(Transition<string>("8", alphabet[1], "5"));

	m.addTransition(Transition<string>("9", alphabet[0], "9"));
	m.addTransition(Transition<string>("9", alphabet[1], "5"));

	// only on start state in a dfa:
	m.defineAsStartState("S");

	// final states:
	m.defineAsFinalState("4");	// Begint op ABB
	m.defineAsFinalState("8");	// Eindigt op BAAB

	m.printTransitions();
}

void PracticumL1R2()
{
	// Begint met 'ABB' of eindigt op BAAB
	std::vector<char> alphabet = { 'a', 'b' };
	Automata<string> m = Automata<string>(alphabet);

	m.addTransition(Transition<string>("S", alphabet[0], "1"));
	m.addTransition(Transition<string>("S", alphabet[1], "2"));

	m.addTransition(Transition<string>("1", alphabet[0], "S"));
	m.addTransition(Transition<string>("1", alphabet[1], "4"));

	m.addTransition(Transition<string>("2", alphabet[0], "1"));
	m.addTransition(Transition<string>("2", alphabet[1], "3"));

	m.addTransition(Transition<string>("3", alphabet[0], "1"));
	m.addTransition(Transition<string>("3", alphabet[1], "2"));

	m.addTransition(Transition<string>("4", alphabet[0], "S"));
	m.addTransition(Transition<string>("4", alphabet[1], "3"));

	// only on start state in a dfa:
	m.defineAsStartState("S");

	// final states:
	m.defineAsFinalState("1");	// Leeg
	m.defineAsFinalState("3");	// Bevat even aantal B's
	m.defineAsFinalState("4");	// Bevat oneven aantal A's

	m.printTransitions();
}

void PracticumL1R3()
{
	std::vector<char> alphabet = { 'a', 'b' };
	Automata<string> m = Automata<string>(alphabet);

	m.addTransition(Transition<string>("S", alphabet[0], "2"));
	m.addTransition(Transition<string>("S", alphabet[1], "1"));

	m.addTransition(Transition<string>("1", alphabet[0], "1"));
	m.addTransition(Transition<string>("1", alphabet[1], "S"));

	m.addTransition(Transition<string>("2", alphabet[0], "3"));
	m.addTransition(Transition<string>("2", alphabet[1], "1"));

	m.addTransition(Transition<string>("3", alphabet[0], "2"));
	m.addTransition(Transition<string>("3", alphabet[1], "4"));

	m.addTransition(Transition<string>("4", alphabet[0], "1"));
	m.addTransition(Transition<string>("4", alphabet[1], "S"));

	// only on start state in a dfa:
	m.defineAsStartState("S");

	// two final states:
	m.defineAsFinalState("4");	// Even aantal B's en eindigt op AAB

	m.printTransitions();
}

void PracticumL1R4()
{
	std::vector<char> alphabet = { 'a', 'b' };
	Automata<string> m = Automata<string>(alphabet);

	m.addTransition(Transition<string>("S", alphabet[0], "1"));
	m.addTransition(Transition<string>("S", alphabet[1], "7"));

	m.addTransition(Transition<string>("1", alphabet[0], "7"));
	m.addTransition(Transition<string>("1", alphabet[1], "2"));

	m.addTransition(Transition<string>("2", alphabet[0], "7"));
	m.addTransition(Transition<string>("2", alphabet[1], "3"));

	m.addTransition(Transition<string>("3", alphabet[0], "4"));
	m.addTransition(Transition<string>("3", alphabet[1], "3"));

	m.addTransition(Transition<string>("4", alphabet[0], "5"));
	m.addTransition(Transition<string>("4", alphabet[1], "3"));

	m.addTransition(Transition<string>("5", alphabet[0], "3"));
	m.addTransition(Transition<string>("5", alphabet[1], "6"));

	m.addTransition(Transition<string>("6", alphabet[0], "6"));
	m.addTransition(Transition<string>("6", alphabet[1], "6"));

	m.addTransition(Transition<string>("7", alphabet[0], "7"));
	m.addTransition(Transition<string>("7", alphabet[1], "7"));

	// only on start state in a dfa:
	m.defineAsStartState("S");

	// two final states:
	m.defineAsFinalState("6");	// Begint met ABB en bevat baab

	//cout << m.accept("aabaab") << endl; returns 0 == false;
	//cout << m.accept("abbaab") << endl; returns 1 == true;

	//m.printTransitions();
}

bool CheckTransition(std::set<char> cSet, string word)
{
	std::vector<char> alphabet(cSet.begin(), cSet.end());
	Automata<string> m = Automata<string>(alphabet);

	m.addTransition(Transition<string>("S", alphabet[0], "1"));
	m.addTransition(Transition<string>("S", alphabet[1], "7"));

	m.addTransition(Transition<string>("1", alphabet[0], "7"));
	m.addTransition(Transition<string>("1", alphabet[1], "2"));

	m.addTransition(Transition<string>("2", alphabet[0], "7"));
	m.addTransition(Transition<string>("2", alphabet[1], "3"));

	m.addTransition(Transition<string>("3", alphabet[0], "4"));
	m.addTransition(Transition<string>("3", alphabet[1], "3"));

	m.addTransition(Transition<string>("4", alphabet[0], "5"));
	m.addTransition(Transition<string>("4", alphabet[1], "3"));

	m.addTransition(Transition<string>("5", alphabet[0], "3"));
	m.addTransition(Transition<string>("5", alphabet[1], "6"));

	m.addTransition(Transition<string>("6", alphabet[0], "6"));
	m.addTransition(Transition<string>("6", alphabet[1], "6"));

	m.addTransition(Transition<string>("7", alphabet[0], "7"));
	m.addTransition(Transition<string>("7", alphabet[1], "7"));

	// only on start state in a dfa:
	m.defineAsStartState("S");

	// two final states:
	m.defineAsFinalState("6");
	m.printTransitions();

	return m.accept(word);
}

void CheckWord()
{
	string word;
	std::set<char> alphabet;

	cout << "Voer string in" << endl;
	cin >> word;

	for (char c : word)
	{
		alphabet.insert(c);
	}
	cout << ((CheckTransition(alphabet, word)) ? "Accepted" : "Rejected") << endl;
}

void printLanguageAsString(set<string> s) {
	for (string const& taal : s)
	{
		std::cout << taal << ' ';
	}
	std::cout << endl;
}

void TestRegExp() {
	RegExp *a, *b, *expr1, *expr2, *expr3, *expr4, *expr5, *all;

	a = new RegExp("a");
	b = new RegExp("b");

	// expr1: "baa"
	expr1 = new RegExp("baa");
	// expr2: "bb"
	expr2 = new RegExp("bb");
	// expr3: "baa | baa"
	expr3 = expr1->or(expr2);

	// all: "(a|b)*"
	all = (a->or(b))->star();

	// expr4: "(baa | baa)+"
	expr4 = expr3->plus();
	// expr5: "(baa | baa)+ (a|b)*"
	expr5 = expr4->dot(all);

	cout << "taal van (baa):\n";
	printLanguageAsString(expr1->getLanguage(5));
	cout << "taal van (bb):\n";
	printLanguageAsString(expr2->getLanguage(5));
	cout << "taal van (baa | bb):\n";
	printLanguageAsString(expr3->getLanguage(5));
	cout << "taal van (a|b)*:\n";
	printLanguageAsString(all->getLanguage(5));
	cout << "taal van (baa | bb)+:\n";
	printLanguageAsString(expr4->getLanguage(5));
	cout << "taal van (baa | bb)+ (a|b)*:\n";
	printLanguageAsString(expr5->getLanguage(6));
}

void inputRegEx() {
	string input;
	int bracketCounter = 0;
	cout << "Enter Regulare Expression" << endl;
	cin >> input;
	vector<string> regexParts;
	string part;

	for (char c : input)
	{
		part.push_back(c);
		if (c == '(')
		{
			bracketCounter++;
		}
		if (c == ')')
		{
			bracketCounter--;
		}
		if (bracketCounter == 0)
		{	
			if (!regexParts.empty())
			{
				if (isalpha(c) && isalpha(regexParts.back().back())) {
					regexParts.back().push_back(c);
					part = "";
				}
				else if (c == '\*' || c == '\+')
				{
					regexParts.back().push_back(c);
					part = "";
				}
				else
				{
					regexParts.push_back(part);
					part = "";
				}
			}
			else
			{
				regexParts.push_back(part);
				part = "";
			}
		}
	}


	RegExp *exp = new RegExp(input);
}

void inputGrammer()
{
	string input;
	cout << "Enter reguliere grammatica" << endl;
	cin >> input;
}

int main()
{
	int choice;
	cout << endl;
	cout << "1: Voorbeeld Grammatica 1" << endl;
	cout << "2: Voorbeeld Expressie 1" << endl;
	cout << "3: Voorbeeld DFA 1" << endl;
	cout << "4: Voorbeeld NFA 1" << endl;
	cout << "5: Invoer Grammatica" << endl;
	cout << "6: Invoer Expressie" << endl;
	cout << "7: Invoer DFA" << endl;
	cout << "8: Invoer NFA" << endl;

	cout << "Maak een keuze: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		break;
	case 2:
		TestRegExp();
		break;
	case 3:
		PracticumL1R1();
		break;
	case 4:
		break;
	case 5:
		inputGrammer();
		break;
	case 6:
		inputRegEx();
		break;
	case 7:
		break;
	case 8:
		break;
	}

	cin >> choice;
}
