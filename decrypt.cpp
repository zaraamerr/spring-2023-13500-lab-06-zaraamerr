#include <iostream>
#include <string>
#include <cctype>
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

// Caesar cipher decryption
//param cipher text and shift
std::string decryptCaesar(std::string ciphertext, int rshift){
    std::string original = ""; //initialized as empty string which will hold the decrypted ciphertext
    int sub = 26 - rshift; 
    for(char c : ciphertext){ //loop thru every char in cipher text
        if(isalpha(c)){ //if an alphabetic char 
            original += shiftChar(c,sub); //shifted back
        }
        else{
            original += c; //regular char no shift
        }
    }
    return original;
}

//param cipher text and keyword
std::string decryptVigenere(std::string ciphertext, std::string keyword){
    std::string plain = ""; //initialize to empty str
    int j = 0; // for looping through the keyword
    for(char c : ciphertext){ //looping through cipher text 
        if(j > keyword.length() - 1){ //if j is > than the index of last letter, set it back to 0
            j = 0;
        }
        if(isalpha(c)){ // if the char is in the alphabet
            plain += shiftChar(c, 26 - (keyword[j] - 97)); //shiftChar, index of speific character in chiper text
            j += 1;                                     //26 - (keyword[j] - 97), the keyword number will be at least 97 or at most 122
        }                                               //so 26 - (keyword[j] - 97) will give you a number you can use in shiftChar
        else{                                           //without error
            plain += c; //if it isn't a char
        }
    }
    return plain;
}