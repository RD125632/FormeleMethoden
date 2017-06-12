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

	// Punt 4
	cout << "41: Voorbeeld Thompson Constructie " << endl;
	// Punt 5
	// Punt 6
	// Punt 7
	// Punt 8
	cout << "81: Geef webgraphz Grammatica" << endl;
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
	case 17:/**/
		testLib.GetLanguageFromRegEx1();
		break;
	case 18:
		testLib.GetLanguageFromRegEx2();
		break;
	case 19:
		testLib.GetLanguageFromRegEx3();
		break;
	case 21:
		testLib.GetLanguageFromRegEx3();
		break;
	case 22:
		testLib.GetLanguageFromRegEx3();
		break;
	case 23:
		testLib.GetLanguageFromRegEx3();
		break;

	}


//<<<<<<< HEAD
//	cout << "0: Invoer woord met DFA check" << endl;
//	cout << "1: Geef woorden gefiltert door DFA" << endl;
//	//cout << "1: Voorbeeld Grammatica 1" << endl;
//	cout << "2: Voorbeeld Expressie 1" << endl;
//	cout << "3: Voorbeeld DFA 1" << endl;
//	cout << "4: Voorbeeld NFA 1" << endl;
//	cout << "5: Invoer Grammatica" << endl;
//	cout << "6: Invoer Expressie" << endl;
//	cout << "7: Invoer DFA" << endl;
//	cout << "8: Invoer NFA" << endl;
//	cout << "9: Thompson" << endl;
//=======
//	cout << "0: Geef taal regex" << endl;					// Example Regex
//	cout << "1: Geef webgraphz DFA Grammatica" << endl;		// Example Webgraphz
//	cout << "2: Invoer woord met DFA check" << endl;		// Example DFA
//	cout << "3: Grammatica > NFA" << endl;					// Grammatica -> NFA			
//	//cout << "5: Regex > Grammatica" << endl;				// Regex -> Grammatica			
//	//cout << "6: Regex -> NFA" << endl;					// Regex -> NFA					WIP		: Thompson
//	cout << "6: N(D)FA -> Grammatica" << endl;				// NFA -> Grammatica							
//	//cout << "7: NFA -> DFA" << endl;						// N(D)FA -> Grammatica
//	//cout << "8: DFA Reverse" << endl;						// DFA -> NFA							: Reverse
//	//cout << "9: DFA Minimaliseren" << endl;				// DFA -> DFA							: Minimaliseren
//>>>>>>> WIP-Grammatica



//	switch (choice)
//	{
//	case 0:
//		testLib.GetLanguageFromRegEx();
//		break;
//	case 1:
//<<<<<<< HEAD
//		testLib.TryWords();
//=======
//		testLib.PracticumL1R1();
//>>>>>>> WIP-Grammatica
//		break;
//	case 2:
//		testLib.InputWord();
//		break;
//	case 3:
//<<<<<<< HEAD
//		testLib.PracticumL1R1();
//		break;
//	case 4:
//		testLib.NFA2();
//		break;
//	case 5:
//=======
//>>>>>>> WIP-Grammatica
//		testLib.InputGrammer();
//		break;
//	case 6:
//		testLib.InputNFA();
//		break;
//	case 9:
//		testLib.Thompson();
//		break;
//	}

	// Hold Console
	getchar();
}
