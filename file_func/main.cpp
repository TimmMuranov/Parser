#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <filesystem>

#include "createFiles.hpp"

 int main(){
    std::cout << "Введите файл...\n";
    std::string s;
    std:: cin >> s;
    // std::cout << "Введите данные...\n";
    // std::string s1;
    // std:: cin >> s1;
    createFiles(s);
 }
