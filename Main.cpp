

#include <iostream>
#include <fstream>
#include <string>
#include "Morse_Coder.h"

using namespace std;

int main() {
    string plaintext_in, plaintext_out, ciphertext_in, ciphertext_out;
    plaintext_in = "Iamfree";
    ciphertext_in = "--. .. -- --..";
    Morse_Coder session = Morse_Coder();
	ciphertext_out = session.encode_to_code(plaintext_in);
	plaintext_out = session.decode_to_text(ciphertext_in);

    cout << endl;
    cout << "Morse code for " << '"' << plaintext_in << '"' << " is:  " << ciphertext_out << endl << endl;
    cout << "The plain text for " << '"' << ciphertext_in << '"' << " is:  " << plaintext_out << endl << endl;

    system("pause");
    return 0;
}