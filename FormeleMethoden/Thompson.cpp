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
	Automata<string>* automata = new Automata<string>();
	string leftState = "0";
	string rightState = "1";
	int counter = 2;

	automata->defineAsStartState(leftState);
	automata->defineAsFinalState(rightState);

	thompsonSwitch(reg, automata, counter, leftState, rightState);
	return automata;
}

void Thompson::plusOperator(RegExp* reg, Automata<string>* automata, int &counter, string leftState, string rightState)
{
	counter++;
	int state2 = counter;
	counter++;
	int state3 = counter;

	automata->addTransition(Transition<string>(leftState, Transition<string>::EPSILON, std::to_string(state2)));
	automata->addTransition(Transition<string>(std::to_string(state3), Transition<string>::EPSILON, std::to_string(state2)));
	automata->addTransition(Transition<string>(std::to_string(state3), Transition<string>::EPSILON, rightState));
	thompsonSwitch(reg->getLeft(), automata, counter, std::to_string(state2), std::to_string(state3));
}

void Thompson::starOperator(RegExp* reg, Automata<string>* automata, int &counter, string leftState, string rightState)
{
	counter++;
	int state2 = counter;
	counter++;
	int state3 = counter;

	automata->addTransition(Transition<string>(leftState, Transition<string>::EPSILON, std::to_string(state2)));
	automata->addTransition(Transition<string>(std::to_string(state3), Transition<string>::EPSILON, std::to_string(state2)));
	automata->addTransition(Transition<string>(std::to_string(state3), Transition<string>::EPSILON, rightState));
	automata->addTransition(Transition<string>(leftState, Transition<string>::EPSILON, rightState));
	thompsonSwitch(reg->getLeft(), automata, counter, std::to_string(state2), std::to_string(state3));
}

void Thompson::orOperator(RegExp* reg, Automata<string>* automata, int &counter, string leftState, string rightState)
{
	counter++;
	int state2 = counter;
	counter++;
	int state3 = counter;
	counter++;
	int state4 = counter;
	counter++;
	int state5 = counter;

	automata->addTransition(Transition<string>(leftState, Transition<string>::EPSILON, std::to_string(state2)));
	automata->addTransition(Transition<string>(leftState, Transition<string>::EPSILON, std::to_string(state4)));
	automata->addTransition(Transition<string>(std::to_string(state3), Transition<string>::EPSILON, rightState));
	automata->addTransition(Transition<string>(std::to_string(state5), Transition<string>::EPSILON, rightState));
	thompsonSwitch(reg->getLeft(), automata, counter, std::to_string(state2), std::to_string(state3));
	thompsonSwitch(reg->getRight(), automata, counter, std::to_string(state4), std::to_string(state5));
}

void Thompson::dotOperator(RegExp* reg, Automata<string>* automata, int &counter, string leftState, string rightState)
{
	counter++;
	int newState = counter;

	thompsonSwitch(reg->getLeft(), automata, counter, leftState, std::to_string(newState));
	thompsonSwitch(reg->getRight(), automata, counter, std::to_string(newState), rightState);
}

void Thompson::oneOperator(RegExp* reg, Automata<string>* automata, int &counter, string leftState, string rightState)
{
	//set alphabet
	char symbol = reg->getTerminals().at(0);
	std::vector<char> symbols = automata->getAlphabet();
	symbols.push_back(symbol);
	automata->setAlphabet(symbols);

	//add transitions
	if (reg->getTerminals().length() == 1) {
		automata->addTransition(Transition<string>(leftState, symbol, rightState));
	}
	else {

		int tempLeftState = std::stoi(leftState);
		int i = 0;
		while (i < reg->getTerminals().length() - 1)
		{
			counter++;
			automata->addTransition(Transition<string>(std::to_string(tempLeftState), reg->getTerminals().at(i), std::to_string(counter)));
			tempLeftState = counter;
			i++;
		}
		//automata->addTransition(Transition<string>(leftState, symbol, std::to_string(tempCounter)));
		/*int i = 1;
		while (i < reg->getTerminals().length() - 1) {
			automata->addTransition(Transition<string>(std::to_string(tempCounter), reg->getTerminals().at(i), std::to_string((tempCounter + 1))));
			tempCounter++;
			counter = &tempCounter;
			i++;
		}*/
		automata->addTransition(Transition<string>(std::to_string(counter), reg->getTerminals().at(i), rightState));
		counter++;
	}
}

void Thompson::thompsonSwitch(RegExp* reg, Automata<string>* automata, int &counter, string leftState, string rightState)
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
