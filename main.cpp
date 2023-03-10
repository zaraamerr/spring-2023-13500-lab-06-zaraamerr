#include <iostream>
#include <cctype>
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

int main()
{
  // Driver code to test the functions
    std::cout << encryptCaesar("Hello, World!", 10) << std::endl;
    std::cout << encryptCaesar("Way to Go!", 5) << std::endl;
    std::cout << encryptVigenere("Hello, World!", "cake") << std::endl;
    std::cout << encryptVigenere("I love coding", "joke") << std::endl;
    std::cout << decryptCaesar("Rovvy, Gybvn!", 10) << std::endl;
    std::cout << decryptCaesar("Bfd yt Lt!", 5) << std::endl;
    std::cout << decryptVigenere("Jevpq, Wyvnd!", "cake") << std::endl;
    std::cout << decryptVigenere("R zyzn qyhrbq", "joke") << std::endl;
    return 0;
}
