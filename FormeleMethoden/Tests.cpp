#include "Tests.h"
#include "Automata.h"
#include "Transition.h"



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


/*	Check the given word with Regular Grammer
*	Input: Word
*	Output: WIP
*/
void Tests::InputGrammer()
{
	string input;
	cout << "Enter reguliere grammatica" << endl;
	cin >> input;
}
