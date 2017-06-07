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
	cout << "2: Geef webgraphz DFA Grammatica" << endl;		// Example Webgraphz
	cout << "3: Invoer woord met DFA check" << endl;		// Example DFA
	cout << "4: Grammatica > NFA" << endl;					// Grammatica -> NFA			WIP
	//cout << "5: Regex > Grammatica" << endl;				// Regex -> Grammatica			
	//cout << "6: Regex -> NFA" << endl;					// Regex -> NFA					WIP		: Thompson
	//cout << "7: N(D)FA -> Grammatica" << endl;			// NFA -> DFA							
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
	case 2:
		testLib.PracticumL1R1();
		break;
	case 3:
		testLib.InputWord();
		break;
	case 4:
		testLib.InputGrammer();
		break;

		/*
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
		break;*/
	}
	// Hold Console
	getchar();
}
