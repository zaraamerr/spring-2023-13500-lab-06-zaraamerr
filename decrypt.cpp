#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
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

// Calculates the frequency of a letter in a string and returns it as a percentage
double freq(char letter, std::string encrypted_str){
    int len = encrypted_str.length();
    double freq = 0; //keep track of how many times a letter appears in a given str
    for(int i = 0; i < len; i++){ //go thru every char in the str
        if(tolower(encrypted_str[i]) == tolower(letter)){ //check if current char
                                            //in str is the same as the given letter, ignoring case
            freq++; //if true, increment freq
        }
    }
    freq = freq/len * 100; // Convert freq to percentage
    return freq;
}

// Calculates the distance between two arrays using the distance formula in 26 dimensions
double distance(double * letter, double * encrypted){
    double result = 0; //initialize to 0
    for(int i = 0; i < 26; i++){
        result += pow(letter[i]-encrypted[i],2);
    }
    result = sqrt(result);
    return result;
}

// Solves the Caesar cipher by trying all 26 possible rotations and choosing the one with the smallest distance
std::string solve(std::string encrypted_str){
    std::string result; //hold the decrypted string
    //all the english alphabet letters
    char letter[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    //the expected frequency of each letter in the English language
    double letterFreq[26] = {8.2,1.5,2.8,4.3,13,2.2,2,6.1,7,0.15,0.77,4,2.4,6.7,7.5,1.9,0.095,6,6.3,9.1,2.8,0.98,2.4,0.15,2,0.074};
    //stores freq of each letter in the encrypted str
    double encryptFreq[26] = {};
    for(int i = 0; i < 26; i++){ // Calculate the frequency of each letter in the encrypted string
        encryptFreq[i] = freq(letter[i], encrypted_str);
    }
    std::string rotation; //will hold the decrypted str after rotation
    int shift; //shift value of current rotation
    double lowestDist = distance(letterFreq, encryptFreq); // Initialize to the distance between the encrypted string and English letter frequencies
    for(int j=0; j < 26; j++){ // Try all 26 possible rotations
        rotation = decryptCaesar(encrypted_str, j); // Decrypt the string with the current shift value
        for(int k = 0; k < 26; k++){ // Calculate the frequency of each letter in the rotated string
            encryptFreq[k] = freq(letter[k], rotation);
        }
        if(lowestDist > distance(letterFreq,encryptFreq)){ // If the new distance is lower than the current lowest distance, update the result
            shift = j;
            lowestDist = distance(letterFreq,encryptFreq);
            result = decryptCaesar(encrypted_str, shift);
        }
    }
    return result;
}
