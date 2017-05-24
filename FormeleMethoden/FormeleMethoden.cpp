#include <stdio.h>
#include <windows.h>   // WinApi header

#include "Tests.h"

using namespace std;

int main()
{
	Tests testLib;
	testLib.InputWithRegEx();

	// Hold Console
	getchar();
}
