#include <stdio.h>
#include <windows.h>   // WinApi header
#include <iostream>

#include "Tests.h"

using namespace std;

int main()
{
	Tests testLib;
	int choice;
	cout << endl;
	cout << "0: Invoer woord met DFA check" << endl;
	cout << "1: Voorbeeld Grammatica 1" << endl;
	cout << "2: Voorbeeld Expressie 1" << endl;
	cout << "3: Voorbeeld DFA 1" << endl;
	cout << "4: Voorbeeld NFA 1" << endl;
	cout << "5: Invoer Grammatica" << endl;
	cout << "6: Invoer Expressie" << endl;
	cout << "7: Invoer DFA" << endl;
	cout << "8: Invoer NFA" << endl;
	cout << "9: Thompson" << endl;

	cout << "Maak een keuze: ";
	cin >> choice;

	switch (choice)
	{
	case 0:
		testLib.InputWord();
		break;
	case 1:
		break;
	case 2:
		testLib.RegExpessie();
		break;
	case 3:
		testLib.PracticumL1R1();
		break;
	case 4:
		break;
	case 5:
		testLib.InputGrammer();
		break;
	case 6:
		testLib.InputWithRegEx();
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		testLib.Thompson();
		break;
	}
	// Hold Console
	getchar();
}
