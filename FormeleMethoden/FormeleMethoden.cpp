#include <stdio.h>
#include <windows.h>   // WinApi header
#include <iostream>

#include "Tests.h"

using namespace std;

/*
Voor Testen(Extra)
- 3 NFA Voorbeelden met epsilon overgangen (Hardcoded)
- DFA implementeren van geaccepteerde/niet geaccepteerde worden lijst
- Regex implementeren van niet geaccepteerde worden lijst
*/

int main()
{
	Tests testLib;
	int choice;
	cout << endl;
	cout << "Menu:" << endl;
	// Punt 1
	cout << "11: Voorbeeld DFA 1 " << endl;
	cout << "12: Voorbeeld DFA 2 " << endl;
	cout << "13: Voorbeeld DFA 3 " << endl;
		cout << "14: Voorbeeld NFA 1 " << endl;
		cout << "15: Voorbeeld NFA 2 " << endl;
		cout << "16: Voorbeeld NFA 3 " << endl; 
	cout << "17: Voorbeeld REG 1 " << endl;
	cout << "18: Voorbeeld REG 2 " << endl; 
	cout << "19: Voorbeeld REG 3 " << endl;
	// Punt 2
	cout << "21: Geef taal van Reguliere Expressie " << endl;
	cout << "22: Check gegenereerde woorden " << endl;
	cout << "23: Check ingevoerde woord met DFA " << endl;
	// Punt 3
	cout << "31: Genereer DFA die op de invoer begint" << endl;
	cout << "32: Genereer DFA die de invoer bevat" << endl;
	cout << "33: Genereer DFA die op de invoer eindigt" << endl;
	cout << "34: Maak ontkenning van DFA" << endl;
	// Punt 4
	cout << "41: Voorbeeld Thompson Constructie " << endl;
	// Punt 5
	// Punt 6
	// Punt 7
	// Punt 9
	cout << "91: Invoer Grammatica naar NFA " << endl;
	cout << "92: Hardcode NFA naar Grammatica" << endl;
	
	cout << "Maak een keuze: ";
	cin >> choice;


	switch (choice)
	{
	case 11:
		testLib.PracticumL1R1();
		break;
	case 12:
		testLib.PracticumL1R2();
		break;
	case 13:
		testLib.PracticumL1R3();
		break;
	case 14:
		testLib.NFA1();
		break;
	case 15:
		testLib.NFA2();
		break;
	case 16:
		testLib.NFA3();
		break;
	case 17:
		testLib.GetLanguageFromRegEx1();
		break;
	case 18:
		testLib.GetLanguageFromRegEx2();
		break;
	case 19:
		testLib.GetLanguageFromRegEx3();
		break;
/**/
	case 21:
		testLib.InputWithRegEx();
		break;
	case 22:
		testLib.TryWords();
		break;
	case 23:
		testLib.InputWord();
		break;
/**/
	case 31:
		testLib.DFABegin();
		break;
	case 32:
		testLib.DFAContain();
		break;
	case 33:
		testLib.DFAEnd();
		break;
	case 34:
		testLib.DFADenail();
		break;
/**/
	case 41:
		testLib.Thompson();
		break;
/**/

	case 91:
		testLib.InputGrammer();
		break;
	case 92:
		testLib.InputNFA();
		break;
	}

	// Hold Console
	getchar();
}
