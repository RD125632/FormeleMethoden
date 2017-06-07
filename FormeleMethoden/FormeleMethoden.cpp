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
	cout << "0: Geef taal regex" << endl;					// Example Regex
	cout << "1: Geef webgraphz DFA Grammatica" << endl;		// Example Webgraphz
	cout << "2: Invoer woord met DFA check" << endl;		// Example DFA
	cout << "3: Grammatica > NFA" << endl;					// Grammatica -> NFA			
	//cout << "5: Regex > Grammatica" << endl;				// Regex -> Grammatica			
	//cout << "6: Regex -> NFA" << endl;					// Regex -> NFA					WIP		: Thompson
	cout << "6: N(D)FA -> Grammatica" << endl;				// NFA -> Grammatica							
	//cout << "7: NFA -> DFA" << endl;						// N(D)FA -> Grammatica
	//cout << "8: DFA Reverse" << endl;						// DFA -> NFA							: Reverse
	//cout << "9: DFA Minimaliseren" << endl;				// DFA -> DFA							: Minimaliseren

	cout << "Maak een keuze: ";
	cin >> choice;

	switch (choice)
	{
	case 0:
		testLib.GetLanguageFromRegEx();
		break;
	case 1:
		testLib.PracticumL1R1();
		break;
	case 2:
		testLib.InputWord();
		break;
	case 3:
		testLib.InputGrammer();
		break;
	case 6:
		testLib.InputNFA();
		break;
	}

	// Hold Console
	getchar();
}
