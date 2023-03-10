#include <iostream>
#include <string>
#include <cctype>
#include "caesar.h"
#include "vigenere.h"

// A helper function to shift one character by rshift
//param: char and shift
//return: char
char shiftChar(char c, int shift) {
    if (!isalpha(c)) { //checks if NOT alphabetic char
        return c; // don't shift non-alphabetic chars
    }
    char start = isupper(c) ? 'A' : 'a'; // sets the value of start to either 'A' or 'a' based on whether
                                        // the input char c is uppercase or lowercase, respectively
    return start + (c - start + shift) % 26; //Calculate the shifted character by first subtracting
    //'start' from 'c' to get the index of the letter in the alphabet. Then add 'shift' to this index 
    //and take the result modulo 26 to ensure that the result stays within the range of the alphabet. 
    //Finally, it adds the starting char value start back to the result to get the final shifted char.
}


// Caesar cipher encryption
std::string encryptCaesar(std::string plaintext, int rshift) {
    std::string encryptedText = ""; //initialized as empty string
    for(char c : plaintext) { //iterates thru every char in the plaintext
        encryptedText += shiftChar(c, rshift); //concatenates the shifted 
                                    // chars into the encrypted text var
    }
    return encryptedText; //return the encrypted text
}
