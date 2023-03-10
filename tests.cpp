#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

// add your tests here
TEST_CASE("Encrypt Caesar Test Cases")
{
    CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
    CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
}

TEST_CASE("Encrypt Vigenere Test Cases")
{
    CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
    CHECK(encryptVigenere("I love coding", "joke") == "R zyzn qyhrbq");
}

TEST_CASE("Decrypt Caesar and Decrypt Vigenere Test Cases")
{
    CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
    CHECK(decryptCaesar("Bfd yt Lt!", 5) == "Way to Go!");
    CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
    CHECK(decryptVigenere("R zyzn qyhrbq", "joke") == "I love coding");
}