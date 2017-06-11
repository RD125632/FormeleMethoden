#include "RegExp.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

#include "Automata.h"
#include "Thompson.h"
#include "Transition.h"

Automata<string>* Thompson::createAutomata(RegExp * reg)
{
	Automata<string>* automata= new Automata<string>();
	int counter = 1;
	string leftState = "0";
	string rightState = "1";

	automata->defineAsStartState(leftState);
	automata->defineAsFinalState(rightState);

	thompsonSwitch(reg, automata, counter, leftState, rightState);

	return automata;
}

void Thompson::plusOperator(RegExp* reg, Automata<string>* automata, int counter, string leftState, string rightState)
{
	int newLeftState = counter + 1;
	int newRightState = newLeftState + 1;
	counter = newRightState;

	automata->addTransition(Transition<string>(leftState, Transition<string>::EPSILON, std::to_string(newLeftState)));
	automata->addTransition(Transition<string>(std::to_string(newRightState), Transition<string>::EPSILON, rightState));
	automata->addTransition(Transition<string>(std::to_string(newRightState), Transition<string>::EPSILON, std::to_string(newLeftState)));
	thompsonSwitch(reg->getLeft(), automata, counter, std::to_string(newLeftState), std::to_string(newRightState));
}

void Thompson::starOperator(RegExp* reg, Automata<string>* automata, int counter, string leftState, string rightState)
{
	int newLeftState = counter + 1;
	int newRightState = newLeftState + 1;
	counter = newRightState;

	automata->addTransition(Transition<string>(leftState, Transition<string>::EPSILON, rightState));
	automata->addTransition(Transition<string>(leftState, Transition<string>::EPSILON, std::to_string(newLeftState)));
	automata->addTransition(Transition<string>(std::to_string(newRightState), Transition<string>::EPSILON, rightState));
	automata->addTransition(Transition<string>(std::to_string(newRightState), Transition<string>::EPSILON, std::to_string(newLeftState)));
	thompsonSwitch(reg->getLeft(), automata, counter, std::to_string(newLeftState), std::to_string(newRightState));
}

void Thompson::orOperator(RegExp* reg, Automata<string>* automata, int counter, string leftState, string rightState)
{
	int newLeftState = counter + 1;
	int newRightState = newLeftState + 1;
	counter = newRightState;
	
	automata->addTransition(Transition<string>(leftState, Transition<string>::EPSILON, std::to_string(newLeftState)));
	automata->addTransition(Transition<string>(std::to_string(newRightState), Transition<string>::EPSILON, rightState));
	thompsonSwitch(reg->getLeft(), automata, counter, std::to_string(newLeftState), std::to_string(newRightState));

	newLeftState = counter + 1;
	newRightState = newLeftState + 1;
	counter = newRightState;
	automata->addTransition(Transition<string>(leftState, Transition<string>::EPSILON, std::to_string(newLeftState)));
	automata->addTransition(Transition<string>(std::to_string(newRightState), Transition<string>::EPSILON, rightState));
	thompsonSwitch(reg->getRight(), automata, counter, std::to_string(newLeftState), std::to_string(newRightState));
}

void Thompson::dotOperator(RegExp* reg, Automata<string>* automata, int counter, string leftState, string rightState)
{
	counter = counter + 1;
	thompsonSwitch(reg->getLeft(), automata, counter, leftState, std::to_string(counter));
	thompsonSwitch(reg->getRight(), automata, counter, std::to_string(counter), rightState);
}

void Thompson::oneOperator(RegExp* reg, Automata<string>* automata, int counter, string leftState, string rightState)
{
	//dit nog kijken met Richard?
	//var symbol = reg.terminals.First();
	//a._symbols.Add(symbol);
	//a.AddTransition(new Transition<string>($"{leftState}", symbol, $"{rightState}"));
	char symbol = reg->getTerminals()[0];
	std::vector<char> symbols = automata->getAlphabet();
	symbols.push_back(symbol);
	automata->addTransition(Transition<string>(leftState, symbol, rightState));
}

void Thompson::thompsonSwitch(RegExp* reg, Automata<string>* automata, int counter, string leftState, string rightState)
{
	switch (reg->getRegOperator()) {
	case ONE:
		oneOperator(reg, automata, counter, leftState, rightState);
		break;
	case PLUS:
		plusOperator(reg, automata, counter, leftState, rightState);
		break;
	case STAR:
		starOperator(reg, automata, counter, leftState, rightState);
		break;
	case OR:
		orOperator(reg, automata, counter, leftState, rightState);
		break;
	case DOT:
		dotOperator(reg, automata, counter, leftState, rightState);
		break;
	default:
		cout << "De opgegeven operator bestaat niet: " << reg->getRegOperator() << endl;
		break;
	}
}
