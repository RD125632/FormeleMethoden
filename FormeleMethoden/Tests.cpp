#include "Tests.h"
#include "Automata.h"
#include "Transition.h"
#include <sstream>

#include "Grammatica.h"

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

void Tests::PracticumL1R2()
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

void Tests::PracticumL1R3()
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

void Tests::PracticumL1R4()
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

void Tests::RegExpessie() {
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





/*	Check the given word with Regular Grammer
*	Input: Word
*	Output: Accepted ? Rejected
*/
bool Tests::AcceptWord(std::set<char> cSet, string word)
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

void Tests::GetLanguageFromRegEx() {
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




/*	Check the given word with Regular Expression
*	Input: Word
*	Output: WIP
*/
void Tests::InputWithRegEx()
{
	string input;
	cout << "Enter Regular Expression" << endl;
	cin >> input;
	RegExp *exp = RegExBreakdown(input);
}


RegExp* Tests::RegExBreakdown(string input) 
{
	int bracketCounter = 0;
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



	RegExp *expression = new RegExp();




	return expression;
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

	Automata<string> automata = Automata<string>(grammer->alphabet);
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

	Automata<string> automata = Automata<string>(E);

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
	grammer.getLanguage();
}


