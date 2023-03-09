#include <iostream>
#include <string>
#include <cctype>

int main(){
    std::string input = "Cat :3 Dog";
    for(char c : input){
        std::cout << c << " " << (int)c << std::endl;
    }
    return 0;
}