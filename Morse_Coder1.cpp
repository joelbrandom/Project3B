#include "Morse_Coder.h" 
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Morse_Coder::Morse_Coder() {
    tree = morse_tree();
    code_key = {};
}

Binary_Tree<string> Morse_Coder::morse_tree() {
    // open file for reading & create ifstream object to work with
    ifstream fin("morse.txt");

    // create an empty tree to begin with
    Binary_Tree<string> result("");


    // declare variables to store parts of each line of the file in.
    string line;
    char tmp;
    string letter;

    // for each line in the file

    do { // for each line of file 
        // make the variable local_root a pointer to the tree's root
        BTNode<string>* local_root = result.getRoot();
        getline(fin, line); // get first line of file as string
        stringstream line_of_file; // create a stringstream object
        line_of_file.str(line); // place the current line in the stringstream
        line_of_file >> tmp; // read the first character (the letter) and strore it in temp_char
        letter = convert_char_to_str(tmp); // convert the letter to a string

        // read remaining character in line, creating/traversing left children
       // for '.' characters, and right children for '_' characters.
        while (line_of_file >> tmp) {

            if (tmp == '.') {
                if (local_root->left == NULL) {
                    local_root->left = new BTNode<string>("");
                }
                local_root = local_root->left;
            }
            if (tmp == '_') {
                if (local_root->right == NULL) {
                    local_root->right = new BTNode<string>("");
                }
                local_root = local_root->right;
            }
        }

        local_root->data =letter ;

    } while (!fin.eof()); // there are still lines in the file (Could hard-code this to exactly 26 iterations)

    return result;
}


    string Morse_Coder::convert_char_to_str(char the_char)
    {
        stringstream c;
        string s;
        c << the_char;
        c >> s;
        return s;
    }

	
