#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <filesystem>
#pragma once

int createDir(std::string path){
    if(std::filesystem::exists(path)) return 1;
    std::filesystem::create_directories(path);
    if(!std::filesystem::exists(path)) return -1;
    return 0;
}
int createDir(const char* path){
    if(std::filesystem::exists(path)) return 1;
    std::filesystem::create_directories(path);
    if(!std::filesystem::exists(path)) return -1;
    return 0;
}

int createFile(const std::string& fileName, const std::string& data) {
    std::ofstream f(fileName);
    if (!f.is_open()) {
        return -1;
    }
    f << data;
    f.close();
    return 0;
}
int createFile(const char* fileName, const char* data) {
    std::ofstream f(fileName);
    if (!f.is_open()) {
        return -1; // Файл не был открыт
    }
    f.write(data, strlen(data));
    f.close();
    return 0;
}

//=========================================================
void createFiles(std::string input_file){
    for(int x=0; x<input_file.length(); ++x){
         if(input_file[x] == '/'){
             createDir(input_file.substr(0, x));
        }
    }
    if(input_file[input_file.length()-1] != '/'){
        createFile(input_file, "");
    }
}

void createFiles(std::string input_file, std::string input_data){
    for(int x=0; x<input_file.length(); ++x){
         if(input_file[x] == '/'){
             createDir(input_file.substr(0, x));
        }
    }
    if(input_file[input_file.length()-1] != '/'){
        createFile(input_file, input_data);
    }
}
