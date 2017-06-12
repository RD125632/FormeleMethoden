#include "Tests.h"
#include "Automata.h"
#include "Transition.h"
#include "Thompson.h"


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

void Tests::NFA1()
{
	std::vector<char> alphabet = { 'a', 'b', '$' };
	Automata<string> m = Automata<string>(alphabet);

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
	Automata<string> m = Automata<string>(alphabet);

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
	Automata<string> m = Automata<string>(alphabet);

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
	delete a, b, expr1, expr2, expr3, expr4, expr5, all;
	getchar();
}

void Tests::Thompson()
{
	////(a|b)*
	//RegExp* regex = new RegExp("a");
	//regex = regex->or(new RegExp("b"));
	//regex = regex->star();
	//printThompson(regex);
	//delete regex;

	////((ab))+
	//regex = new RegExp("a");
	//regex = regex->dot(new RegExp("b"));
	//regex = regex->plus();
	//printThompson(regex);
	//delete regex;

	////((a|b)|(a|d))
	//RegExp *rA, *rB, *rC, *rD, *reg;
	//rA = new RegExp("a");
	//rB = new RegExp("b");
	//rC = new RegExp("c");
	//rD = new RegExp("d");

	//reg = rA->or (rB);
	//reg = reg->or(rC->or(rD));
	//printThompson(reg);
	//delete rA, rB, rC, rD, regex;

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
	printThompson(expr5);
}

void Tests::printThompson(RegExp * reg)
{
	cout << "Print Thompson:" << endl;
	cout << reg->toString() <<endl;
	Automata<string>* automata = Thompson::createAutomata(reg);
	automata->printTransitions();
	string woord = "baaab";
	cout << "Check op woord: " << woord << " -> " << ((automata->accept(woord)) ? "Accepted" : "Rejected") << endl;

	cout << "Alphabet:" << endl;
	for(char symbol : automata->getAlphabet())
	{
		cout << symbol << " ";
	}
	cout << "Talen behorende bij de regex:" << endl;
	for(string s : reg->getLanguage(3))
	{
		cout << s << endl;
	}
	getchar();
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
	Automata<string> m = Automata<string>(alphabet);

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
	string input = "((ba)(a|b)*)+";
	cout << "Enter Regular Expression" << endl;
	cin >> input;
	RegExp *exp = RegExBreakdown(input);
	cout << exp->toString();
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
					int j = input.length();
					if (i < j - 1)
					{
						int nextPos = 0;
						if (input.at(i + 1) == '\*')
						{
							nextPos = 1;
							outside.push_back(input.at(i + 1));
							specialRegexPart = regexPart -> star();
							regexPart = specialRegexPart;
						}
						else if (input.at(i + 1) == '\+')
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
	else if (input.find("|") != std::string::npos || input.find("\*") != std::string::npos || input.find("\+") != std::string::npos)
	{
		string leftPart;
		RegExp *expr;
		for (int i = 0; i < input.length(); i++)
		{
			if (input.at(i) == '\*')
			{
				expr = new RegExp(leftPart);
				expr->star();
				return expr;
			}
			else if (input.at(i) == '\+')
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


