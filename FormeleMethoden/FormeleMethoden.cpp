#include <stdio.h>
#include <vector>
#include <set>
#include <string>
#include <windows.h>   // WinApi header

#include "Automata.h"
#include "Transition.h"

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
	std::set<char> alfabet;

	cout << "Voer string in" << endl;
	cin >> word;

	for (char c : word)
	{
		alfabet.insert(c);
	}
	cout << ((CheckTransition(alfabet, word)) ? "Accepted" : "Rejected") << endl;
}

int main()
{
	while (true)
	{
		CheckWord();
	}
}
