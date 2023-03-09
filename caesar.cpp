#include <iostream>
#include <string>
#include <cctype>
#include "caesar.h"

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift) { //param: char and right shift
    if(std::isalpha(c)) { //checks if char is in the alphabet
        //convert char to lowercase
        char lower_c = std::tolower(c);
        // subtract ASCII code for 'a' to shift the range from
        // 0 ≤ rshift ≤ 25. apply the shift of the ASCII code by adding rshift. 
        // do modulo 26 to ensure value can wrap around alphabet if necessary
        // and then add the ASCII code value for 'a' back to shift back to the
        // original range.
        char shifted_c = (lower_c - 'a' + rshift) % 26 + 'a';
        if(std::isupper(c)) { //if the char was originally uppercase
            shifted_c = std::toupper(shifted_c); //convert the shifted char back
                                     //to uppercase if it was originally uppercase.
        }
        return shifted_c; //return shifted char
    }
    else { //if the char is not a part of the alphabet (like punctuation or something)
        return c; //return the char in its original, unchanged form
    }
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
