#include <iostream>
#include <cctype>
#include "caesar.h"

int main()
{
  // Driver code to test the functions
    std::string plaintext = "Hello, World!";
    int rshift = 10;
    std::string encryptedText = encryptCaesar(plaintext, rshift);
    std::cout << "Encrypted text: " << encryptedText << std::endl;
    return 0;
}
