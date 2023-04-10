#pragma once
#include <string>

//add prototypes here
std::string decryptCaesar(std::string ciphertext, int rshift);
std::string decryptVigenere(std::string ciphertext, std::string keyword);
std::string solve(std::string encrypted_string);
double distance(double * letter, double * encrypted);
double freq(char letter, std::string encrypted_string);