// FormeleMethoden.cpp : Defines the entry point for the console application.
//	
//	To create graph of Language copy the code and past on site below
//	http://www.webgraphviz.com/
//
//
//

/*
#include <iostream>
#include <windows.h>   // WinApi header
using namespace std;    // std::cout, std::cin
int main()
{
	HANDLE  hConsole;
	int k;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// you can loop k higher to see more color choices
	for (k = 1; k < 255; k++)
	{
		// pick the colorattribute k you want
		SetConsoleTextAttribute(hConsole, k);
		cout << k << " I want to be nice today!" << endl;
	}

	cin.get(); // wait
	return 0;
}*/

#include <stdio.h>
#include <vector>
#include <string>
#include <windows.h>   // WinApi header

#include "Automata.h"
#include "Transition.h"

using namespace std;

HANDLE  hConsole;
int choice = 0;

// Begint met 'ABB'
void practicum_1A()
{
	std::vector<char> alphabet = { 'a', 'b' };
	Automata<string> m = Automata<string>(alphabet);

	m.addTransition(Transition<string>("S", 'a', "q1"));
	m.addTransition(Transition<string>("S", 'b', "F"));

	m.addTransition(Transition<string>("q1", 'a', "F"));
	m.addTransition(Transition<string>("q1", 'b', "q2"));

	m.addTransition(Transition<string>("q2", 'a', "F"));
	m.addTransition(Transition<string>("q2", 'b', "q3"));
	
	// the end state, loops for a and b:
	m.addTransition(Transition<string>("q3", 'a'));
	m.addTransition(Transition<string>("q3", 'b'));

	// the error state, loops for a and b:
	m.addTransition(Transition<string>("F", 'a'));
	m.addTransition(Transition<string>("F", 'b'));

	// only on start state in a dfa:
	m.defineAsStartState("S");

	// final states:
	m.defineAsFinalState("q3");

	m.printTransitions();
}

// Eindigt op baab
void practicum_1B()
{
	std::vector<char> alphabet = { 'a', 'b' };
	Automata<string> m = Automata<string>(alphabet);

	m.addTransition(Transition<string>("q0", 'a', "q0"));
	m.addTransition(Transition<string>("q0", 'b', "q1"));

	m.addTransition(Transition<string>("q1", 'a', "q2"));
	m.addTransition(Transition<string>("q1", 'b', "q1"));

	m.addTransition(Transition<string>("q2", 'a', "q3"));
	m.addTransition(Transition<string>("q2", 'b', "q1"));

	m.addTransition(Transition<string>("q3", 'a', "q0"));
	m.addTransition(Transition<string>("q3", 'b', "q4"));

	// only on start state in a dfa:
	m.defineAsStartState("q0");

	// two final states:
	m.defineAsFinalState("q4");

	m.printTransitions();
}

void printMenu()
{
	SetConsoleTextAttribute(hConsole, 11);
	cout << endl;
	cout << " Menu" << endl;
	cout << endl;
	cout << " 1 - Practicum 1A" << endl;
	cout << " 2 - Practicum 1B" << endl;
	cout << " 10 - Exit" << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout << " > ";
	cin >> choice;
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
}

int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	while (choice < 10)
	{
		switch (choice)
		{
			// Main options
		case 0:
			printMenu();	
			break;
		case 1:
			practicum_1A();
			choice = 0;
			break;
		case 2:
			practicum_1B();
			choice = 0;
			break;
		}
	}
}
