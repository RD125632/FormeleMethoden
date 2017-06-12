#include "Tests.h"
#include "Automata.h"
#include "Transition.h"
#include "Thompson.h"
#include <sstream>
#include "Grammatica.h"
#include <iostream>
#include <fstream>

using namespace std;

Tests::Tests()
{
}

/*	Homework Assignments for Regular Grammer
*	-
*/
void Tests::PracticumL1R1()
{
	// Begint met 'ABB' of eindigt op BAAB
	std::vector<char> alphabet = { 'a', 'b' };
	Automata<string> m = Automata<string>(Automata<string>::Preset::none, alphabet);

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

void Tests::PracticumL1R2()
{
	// Begint met 'ABB' of eindigt op BAAB
	std::vector<char> alphabet = { 'a', 'b' };
	Automata<string> m = Automata<string>(Automata<string>::Preset::none, alphabet);

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

void Tests::PracticumL1R3()
{
	std::vector<char> alphabet = { 'a', 'b' };
	Automata<string> m = Automata<string>(Automata<string>::Preset::none, alphabet);

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

void Tests::PracticumL1R4()
{
	std::vector<char> alphabet = { 'a', 'b' };
	Automata<string> m = Automata<string>(Automata<string>::Preset::none, alphabet);

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

void Tests::NFA1()
{
	std::vector<char> alphabet = { 'a', 'b', '$' };
	Automata<string> m = Automata<string>(Automata<string>::Preset::none, alphabet);

	m.addTransition(Transition<string>("S", alphabet[0], "1"));
	m.addTransition(Transition<string>("1", alphabet[0], "2"));
	m.addTransition(Transition<string>("2", alphabet[0], "3"));
	m.addTransition(Transition<string>("3", alphabet[0], "4"));

	// only on start state in a dfa:
	m.defineAsStartState("S");

	// two final states:
	m.defineAsFinalState("4");	
	m.printTransitions();
}

void Tests::NFA2()
{
	std::vector<char> alphabet = { 'a', 'b', '$' };
	Automata<string> m = Automata<string>(Automata<string>::Preset::none, alphabet);

	m.addTransition(Transition<string>("S", alphabet[2], "1"));
	m.addTransition(Transition<string>("4", alphabet[2], "2"));
	m.addTransition(Transition<string>("3", alphabet[2], "1"));
	m.addTransition(Transition<string>("1", alphabet[0], "2"));
	m.addTransition(Transition<string>("2", alphabet[1], "3"));
	m.addTransition(Transition<string>("3", alphabet[0], "4"));

	// only on start state in a dfa:
	m.defineAsStartState("S");

	// two final states:
	m.defineAsFinalState("4");
	m.printTransitions();
}

void Tests::NFA3()
{
	std::vector<char> alphabet = { 'a', 'b', '$' };
	Automata<string> m = Automata<string>(Automata<string>::Preset::none, alphabet);

	m.addTransition(Transition<string>("S", alphabet[2], "1"));
	m.addTransition(Transition<string>("1", alphabet[0], "2"));
	m.addTransition(Transition<string>("2", alphabet[0], "3"));
	m.addTransition(Transition<string>("4", alphabet[0], "3"));

	// only on start state in a dfa:
	m.defineAsStartState("S");
	m.defineAsStartState("4");

	// two final states:
	m.defineAsFinalState("3");
	m.printTransitions();
}

void Tests::Thompson()
{
	//RegExp *a, *b, *expr1, *expr2, *expr3, *expr4, *expr5, *expr6, *all;

	//a = new RegExp("a");
	//b = new RegExp("b");

	////expr6: "(a|b)*"
	//expr6 = a->or(b);
	//expr6 = expr6->star();
	//// expr1: "baa"
	//expr1 = new RegExp("baa");
	//// expr2: "bb"
	//expr2 = new RegExp("bb");
	//// expr3: "baa | bb"
	//expr3 = expr1-> or (expr2);

	//// all: "(a|b)*"
	//all = (a-> or (b))->star();

	//// expr4: "(baa | bb)+"
	//expr4 = expr3->plus();
	//// expr5: "(baa | bb)+ (a|b)*"
	//expr5 = expr4->dot(all);

	//RegExp *e1, *e2, *e3, *e4, *e5, *e6, *e7, *e00, *e01, *e02, *e03;
	//e1 = new RegExp("a");
	//e1 = e1->star();
	//e2 = new RegExp("aa");
	//e2 = e2->plus();
	//e3 = new RegExp("ba");
	//e3 = e3->star();
	//e4 = new RegExp("b");
	//e5 = new RegExp("abba");
	//e6 = new RegExp("baab");
	//e7 = new RegExp("bbbb");

	//e00 = e3->dot(e4);
	//e01 = e2-> or (e00);
	//e02 = e5-> or (e6-> or (e7))->plus();
	//e00 = e01->dot(e00)->dot(e02);

	//e00 = e1->dot(e00);

	RegExp *a, *aa, *ba, *b, *abba, *baab, *bbbb, *aster, *aaplus, *baster, *basterb, *e1, *e2, *e3, *e4;
	a = new RegExp("a");
	aster = a->star();
	aa = new RegExp("aa");
	aaplus = aa->plus();
	ba = new RegExp("ba");
	baster = ba->star();
	b = new RegExp("b");
	abba = new RegExp("abba");
	baab = new RegExp("baab");
	bbbb = new RegExp("bbbb");

	basterb = baster->dot(b);
	e1 = aaplus-> or (basterb);
	e2 = aster->dot(e1); //a*(aa+|ba*b)

	e3 = abba-> or (baab)-> or (bbbb);
	e3 = e3->plus(); //(abba|baab|bbbb)+

	e4 = e2->dot(e3);

	printThompson(e4);
}

void Tests::printThompson(RegExp * reg)
{
	cout << "Print Thompson:" << endl;
	cout << reg->toString() <<endl;
	Automata<string>* automata = Thompson::createAutomata(reg);
	automata->printTransitions();
	//cout << "Talen behorende bij de regex:" << endl;
	//for(string s : reg->getLanguage(3))
	//{
	//	cout << s << endl;
	//}
	getchar();
}



/*	Check the given word with Regular Grammer
*	Input: Word
*	Output: Accepted ? Rejected
*/
bool Tests::AcceptWord(std::set<char> cSet, string word)
{
	std::vector<char> alphabet(cSet.begin(), cSet.end());
	Automata<string> m = Automata<string>(Automata<string>::Preset::none, alphabet);

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

void Tests::InputWord()
{
	string word;
	std::set<char> alphabet;

	cout << "Voer string in" << endl;
	cin >> word;

	for (char c : word)
	{
		alphabet.insert(c);
	}
	cout << ((AcceptWord(alphabet, word)) ? "Accepted" : "Rejected") << endl;
}

/*
	Create BeginWith DFA from preset
*/
void Tests::DFABegin()
{
	string word;
	std::set<char> alphabet;
	cout << "DFA Presets" << endl;
	cout << "Start met: " << endl;
	cin >> word;

	for (char c : word)
	{
		alphabet.insert(c);
	}
	Automata<string> m = Automata<string>(word, 
		Automata<string>::Preset::beginWith, 
		vector<char>(alphabet.begin(), alphabet.end()));
	m.printTransitions();
}


/*	Get language of regex with limiter
*	Input: Regex, Limiter
*	Output: Language
*/
void Tests::printLanguageAsString(set<string> s) {
	for (string const& taal : s)
	{
		std::cout << taal << ' ';
	}
	std::cout << endl;
}

void Tests::readRegExpFromFile()
{
	string line;
	ifstream myfile("test.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			InputWithRegEx(line);
			break;
		}
		myfile.close();
	}

	else cout << "Unable to open file";
}

void Tests::saveResultsToFile()
{
	ofstream myfile("test-results.txt");
	if (myfile.is_open())
	{
		myfile << "This is a line.\n";
		myfile << "This is another line.\n";
		myfile.close();
	}
	else cout << "Unable to open file";
}

void Tests::GetLanguageFromRegEx1() {
	RegExp *a, *b, *expr1, *expr2, *expr3, *expr4, *expr5, *all;

	a = new RegExp("a");
	b = new RegExp("b");

	// expr1: "baa"
	expr1 = new RegExp("baa");
	// expr2: "bb"
	expr2 = new RegExp("bb");
	// expr3: "baa | baa"
	expr3 = expr1-> or (expr2);

	// all: "(a|b)*"
	all = (a-> or (b))->star();

	// expr4: "(baa | baa)+"
	expr4 = expr3->plus();
	// expr5: "(baa | baa)+ (a|b)*"
	expr5 = expr4->dot(all);

	cout << "taal van (baa):\n";
	printLanguageAsString(expr1->getLanguage(5));
}

void Tests::GetLanguageFromRegEx2() {
	RegExp *a, *b, *expr1, *expr2, *expr3, *expr4, *expr5, *all;

	a = new RegExp("a");
	b = new RegExp("b");

	// expr1: "baa"
	expr1 = new RegExp("baa");
	// expr2: "bb"
	expr2 = new RegExp("bb");
	// expr3: "baa | baa"
	expr3 = expr1-> or (expr2);

	// all: "(a|b)*"
	all = (a-> or (b))->star();

	// expr4: "(baa | baa)+"
	expr4 = expr3->plus();
	// expr5: "(baa | baa)+ (a|b)*"
	expr5 = expr4->dot(all);

	cout << "taal van (baa | bb)+:\n";
	printLanguageAsString(expr4->getLanguage(5));
}

void Tests::GetLanguageFromRegEx3() {
	RegExp *a, *b, *expr1, *expr2, *expr3, *expr4, *expr5, *all;

	a = new RegExp("a");
	b = new RegExp("b");

	// expr1: "baa"
	expr1 = new RegExp("baa");
	// expr2: "bb"
	expr2 = new RegExp("bb");
	// expr3: "baa | baa"
	expr3 = expr1-> or (expr2);

	// all: "(a|b)*"
	all = (a-> or (b))->star();

	// expr4: "(baa | baa)+"
	expr4 = expr3->plus();
	// expr5: "(baa | baa)+ (a|b)*"
	expr5 = expr4->dot(all);

	cout << "taal van (baa | bb)+ (a|b)*:\n";
	printLanguageAsString(expr5->getLanguage(6));
}

/*
*	Input: Woorden random
*	Output: Niet geaccepteerde woorden
*/

void Tests::GenerateWord(string str, string res, Automata<string> *m) {
	cout << res;
	cout << (m->accept(res) ? " -> Accepted" : " -> Rejected") << endl;

	for (int i = 0; i < str.length(); i++)
		GenerateWord(string(str).erase(i, 1), res + str[i], m);
}

void Tests::TryWords()
{
	std::vector<char> alphabet = { 'a', 'b' };
	Automata<string> m = Automata<string>(Automata<string>::Preset::none, alphabet);

	m.addTransition(Transition<string>("S", alphabet[0], "1"));
	m.addTransition(Transition<string>("S", alphabet[1], "2"));

	m.addTransition(Transition<string>("1", alphabet[0], "1"));
	m.addTransition(Transition<string>("1", alphabet[1], "2"));

	m.addTransition(Transition<string>("2", alphabet[0], "1"));
	m.addTransition(Transition<string>("2", alphabet[1], "2"));

	// only on start state in a dfa:
	m.defineAsStartState("S");

	// two final states:
	m.defineAsFinalState("2");

	string str = "bab";
	cout << "Controleer gegenereerde woorden:" << endl;
	GenerateWord(str, "", &m);
}



/*	
*	Input: Reguliere Expressie
*	Output: Zelfde Expressie
*/
void Tests::InputWithRegEx()
{
	string input;
	//string input = "((ba)(a|b)*)+";
	cout << "Enter Regular Expression" << endl;
	cin >> input;
	RegExp *exp = RegExBreakdown(input);
	cout << exp->toString() << endl;
	for(string s : exp->getLanguage(4))
	{
		cout << s << endl;
	}
	getchar();
}

/*
*	Input: Reguliere Expressie
*	Output: Zelfde Expressie
*/
void Tests::InputWithRegEx(string input)
{
	RegExp *exp = RegExBreakdown(input);
	cout << exp->toString() << endl;
	for (string s : exp->getLanguage(4))
	{
		cout << s << endl;
	}
	getchar();
}


RegExp* Tests::RegExBreakdown(string input) 
{
	int bracketCounter = 0;
	vector<string> regexParts;
	string part, outside;
	RegExp *specialRegexPart, *regexPart;


	if (input.find("(") != std::string::npos || input.find(")") != std::string::npos)
	{
		for (int i = 0; i < input.length(); i++)
		{
			if (bracketCounter >= 1)
			{
				part.push_back(input.at(i));
			}

			if (input.at(i) == '(')
			{
				if (bracketCounter == 0)
				{
					outside.push_back(input.at(i));
				}
				bracketCounter++;
			}
			else if (input.at(i) == ')')
			{
				bracketCounter--;
				if (bracketCounter == 0)
				{
					part.pop_back();

					/* Insert Recursion */
					regexPart = RegExBreakdown(part);

					outside.push_back(input.at(i));
					if (i < input.length() - 1)
					{
						int nextPos = 0;
						if (input.at(i + 1) == '*')
						{
							nextPos = 1;
							outside.push_back(input.at(i + 1));
							specialRegexPart = regexPart -> star();
							regexPart = specialRegexPart;
						}
						else if (input.at(i + 1) == '+')
						{
							nextPos = 1;
							outside.push_back(input.at(i + 1));
							specialRegexPart = regexPart -> plus();
							regexPart = specialRegexPart;
						}
						
						if (input.at(i + 1) == '(')
						{
							string temp = input;
							string findPart = "(" + part + ")";
							size_t pos = temp.find(findPart) + findPart.length();
							string nextInput = temp.substr(nextPos + pos);
							regexPart = regexPart->dot(RegExBreakdown(nextInput));
						}
						return regexPart;
					}
				}
			}
		}
	}
	else if (input.find("|") != std::string::npos || input.find("*") != std::string::npos || input.find("+") != std::string::npos)
	{
		string leftPart;
		RegExp *expr;
		for (int i = 0; i < input.length(); i++)
		{
			if (input.at(i) == '*')
			{
				expr = new RegExp(leftPart);
				expr->star();
				return expr;
			}
			else if (input.at(i) == '+')
			{
				expr = new RegExp(leftPart);
				expr->plus();
				return expr;
			}
			else if (input.at(i) == '|')
			{
				string rightPart = input.substr(i+1);

				RegExp* tempExpr = new RegExp(leftPart);
				expr = tempExpr-> or (new RegExp(rightPart));
				return expr;
			}
			leftPart.push_back(input.at(i));
		}
	}
	else
	{
		return new RegExp(input);
	}
	return nullptr;
}


/*
*	Input: Grammatica
*	Output: NFA
*/
void Tests::InputGrammer()
{
	string input, token;
	vector<char> E;
	vector<string> N, S;
	vector<Transition<string>> P;

	cout << "Enter reguliere grammatica: G(N,E,P,S)" << endl;
	cout << "Verzameling van alle states (N):" << endl;
	cin >> input;
	stringstream states(input);


	while (getline(states, token, ','))
	{
		N.push_back(token);
	}

	cout << "Alfabet (E): " << endl; 
	cin >> input;
	stringstream alfabet(input);

	while (getline(alfabet, token, ','))
	{
		E.push_back(token[0]);
	}

	cout << "Productieregels (P): {" << endl;
	bool moreRules = true;
	while(moreRules)
	{
		cin >> input;
		string fromState = "";
		char character;
		string toState = "";

		string temp;
		int partCount = 0;
		for (char c : input)
		{
			if (c == ',')
			{			

				temp.clear();
				partCount++;
			}
			else if (c == '}')
			{
				moreRules = false;
			}
			else
			{
				temp += c;
				switch (partCount)
				{
				case 0:
					fromState = temp;
					break;
				case 1:
					character = temp.back();
					break;
				case 2:
					toState = temp;
					break;
				}
			}	
		}

		if(!fromState.empty() && !toState.empty())
			P.push_back(Transition<string>(fromState, character, toState));
	}

	cout << "Startstates: (S): " << endl;
	cin >> input;
	stringstream startstate(input);
	while (getline(startstate, token, ','))
	{
		S.push_back(token);
	}
	
	Grammatica<string> grammer = Grammatica<string>(N, E, P, S);
	Tests::GrammaticaToNfa(&grammer);
}

void  Tests::GrammaticaToNfa(Grammatica<string>* grammer)
{
	cout << "Omzetten van Reguliere Grammatica naar NFA....." << endl;
	string input, token;

	Automata<string> automata = Automata<string>(Automata<string>::Preset::none, grammer->alphabet);
	for (Transition<string> t : grammer->transitions)
		automata.addTransition(t);
	for (string s : grammer->startStates)
		automata.defineAsStartState(s);
	
	cout << "De Reguliere Grammatica mist eindtoestanden." << endl;
	cout << "Eventuele eindtoestanden: ";
	cin >> input;
	stringstream endstates(input);

	while (getline(endstates, token, ','))
	{
		automata.defineAsFinalState(token);
	}
	automata.printTransitions();
}


/*	Check the given word with Regular Grammer
*	Input: NFA
*	Output: Grammatica

{(0, 'a'): [1], (2, '$'): [0, 3], (3, 'b'): [4], (4, '$'): [5], (0, '$'): [5], (5, 'a'): [6]}

*/
void Tests::InputNFA()
{
	string input, token;
	vector<char> E;
	vector<string> N, S, F;
	vector<Transition<string>> P;

	cout << "Enter NFA: NFA(N,E,P,S,F)" << endl;
	cout << "Verzameling van alle states (N):" << endl;
	cin >> input;
	stringstream states(input);

	while (getline(states, token, ','))
	{
		N.push_back(token);
	}

	cout << "Alfabet (E): " << endl;
	cin >> input;
	stringstream alfabet(input);

	while (getline(alfabet, token, ','))
	{
		E.push_back(token[0]);
	}

	cout << "Productieregels (P): {" << endl;
	bool moreRules = true;
	while (moreRules)
	{
		cin >> input;
		string fromState = "";
		char character;
		string toState = "";

		string temp;
		int partCount = 0;
		for (char c : input)
		{
			if (c == ',')
			{

				temp.clear();
				partCount++;
			}
			else if (c == '}')
			{
				moreRules = false;
			}
			else
			{
				temp += c;
				switch (partCount)
				{
				case 0:
					fromState = temp;
					break;
				case 1:
					character = temp.back();
					break;
				case 2:
					toState = temp;
					break;
				}
			}
		}

		if (!fromState.empty() && !toState.empty())
			P.push_back(Transition<string>(fromState, character, toState));
	}

	cout << "Startstates: (S): " << endl;
	cin >> input;
	stringstream startstate(input);
	while (getline(startstate, token, ','))
	{
		S.push_back(token);
	}
	cout << "Finalstates: (F): " << endl;
	cin >> input;
	stringstream finalstate(input);
	while (getline(finalstate, token, ','))
	{
		F.push_back(token);
	}

	Automata<string> automata = Automata<string>(Automata<string>::Preset::none, E);

	for (Transition<string> t : P)
		automata.addTransition(t);
	for (string s : S)
		automata.defineAsStartState(s);
	for (string s : F)
		automata.defineAsFinalState(s);

	Tests::NfaToGrammatica(&automata);
}

void  Tests::NfaToGrammatica(Automata<string>* automata)
{
	Grammatica<string> grammer = Grammatica<string>(automata->getStates(), automata->getAlphabet(), automata->getTransitions(), automata->getStartStates());
	//grammer.getLanguage();
}

