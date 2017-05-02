// FormeleMethoden.cpp : Defines the entry point for the console application.
//	
//	To create graph of Language copy the code and past on site below
//	http://www.webgraphviz.com/
//
//
//

#include <stdio.h>
#include <vector>
#include <string>

#include "Automata.h"
#include "Transition.h"

using namespace std;

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
	std::cout << "-------" << endl;
	std::cout << m.isDFA() << endl;
}

int main()
{
	practicum_1B();

	int c;
	cin >> c;
}
