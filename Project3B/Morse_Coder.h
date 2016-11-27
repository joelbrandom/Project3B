#ifndef MORSE_CODER_H
#define MORSE_CODER_H

#include "Binary_Tree.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>



using namespace std;

class Morse_Coder {

public:
    Morse_Coder();
    string Morse_Coder::convert_char_to_str(char the_char);
    Binary_Tree<string> morse_tree();

	string encode_to_code(string text);
	string decode_to_text(string text);

private:
    map<char, string> code_key;
    string plaintext;
    string ciphertext;
    Binary_Tree<string> tree;

   
    





};




#endif
