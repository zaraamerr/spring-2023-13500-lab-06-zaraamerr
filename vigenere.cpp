#include <iostream>
#include <string>
#include <cctype>
#include "caesar.h"
#include "vigenere.h"

//param: plaintext and keyword. 
std::string encryptVigenere(std::string plaintext, std::string keyword) {
    std::string ciphertext = ""; //initialize empty string that will be built one char at a time
    //Start loop that iterates over each letter of the plaintext message. The loop uses two int
    //vars, i and j, to keep track of the current index in the plaintext message and the keyword 
    //respectively. The loop starts with i and j both = 0, and continues as long as i is less than the
    //length of the plaintext message.
    for (int i = 0, j = 0; i < plaintext.length(); i++) {
        char c = plaintext[i]; //current character of the plaintext message at index i

        if (isalpha(c)) { //checks if c is a letter of the alphabet
            int keywordIndex = j % keyword.length(); //calculate the index of the current letter of the
                                            // keyword by taking the current value of j and taking the 
                                            //modulo with the length of the keyword. This ensures that j
                                            //wraps around to the beginning of the keyword when it 
                                            //reaches the end.
            char keywordChar = tolower(keyword[keywordIndex]); //gets the current letter of the keyword
                                                    // at the index keywordIndex, converts it to lowercase
            int shift = keywordChar - 'a'; //calculate shift value to use for encrypting the current plaintext letter

            ciphertext += shiftChar(c, shift); //encrypt the current plaintext letter c using shift
            j++; //increments j to move on to the next letter of the keyword
        } else {
            ciphertext += c; //if the current character of the plaintext message is not a letter 
        }
    }

    return ciphertext;
}



