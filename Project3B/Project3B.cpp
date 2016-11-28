#include "stdafx.h"
#include <iostream>
#include "Morse.h"

int main()
{
	std::string input = "abcdefghijklmnopqrstuvwxyz", input2 = "._ _... _._. _.. . .._. __. .... .. .___ _._ ._.. __ _. ___ .__. __._ ._. ... _ .._ ..._ .__ _.._ _.__ __..";
	Morse morse;
	std::cout << morse.encodeMessage(input) << '\n';
	//std::cout << morse.decoder;
	//BTNode<std::string>* local_root = morse.decoder.getRoot();
	//local_root = local_root->left;
	//std::cout << "left is: " << local_root->data << '\n';
	//std::cout << local_root->left->data << '\n';
	std::cout << morse.decodeMessage(input2) << '\n';
	return 0;
}
