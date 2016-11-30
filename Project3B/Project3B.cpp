#include "stdafx.h"
#include <iostream>
#include "Morse.h"

int main()
{
	std::string input = "abcdefghijklmnopqrstuvwxyz", input2 = "._ _... _._. _.. . .._. __. .... .. .___ _._ ._.. __ _. ___ .__. __._ ._. ... _ .._ ..._ .__ _.._ _.__ __..";
	Morse morse;
	std::cout << morse.encodeMessage(input) << '\n';
	std::cout << morse.decodeMessage(input2) << '\n';
	// Get rid of this below
	system("PAUSE");
	return 0;
}
