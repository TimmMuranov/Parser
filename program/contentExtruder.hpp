// принимает текст, стартовый тег со всеми спецификаторами и его тип (пустой вариант)
//
//#include "contentExtruder.hpp"
//int main (){
//    std::string text = "<1>...</1>...<1 5=5>12<1></1>3</1>...";
//    std::cout << contentExtruder(text, "<1 5=5>", "<1>") << std::endl;
//    // выход: "12<1></1>3"
//    return 0;
//}
#include <iostream>
#include <string>

#pragma once

using namespace std;

string contentExtruder(string file, string startTag, string openTag){
    string closeTag = "</" + openTag.substr(1);
    openTag = openTag.substr(0, openTag.length()-1); //убирю последний символ в теге
    bool openTagFlag = 0;
    int allTagFlag = 0;
    int size = file.length();
    string finFile;
    for(int x=0; x<size; ++x){
        if(file.substr(x, startTag.length()) == startTag){
            //cout << "Точка вхожденя найдена: " << x << endl;
            openTagFlag = 1;
            ++allTagFlag;
            x += startTag.length();
        }
        if(file.substr(x, openTag.length()) == openTag){
            ++allTagFlag;
        }
        if(file.substr(x, closeTag.length()) == closeTag){
            --allTagFlag;
        }
        if(openTagFlag == 1 && !allTagFlag){
            return finFile;
        }
        if(openTagFlag){
            finFile += file[x];
        }
        //cout<<openTag<<endl<<closeTag<<endl<<openTagFlag<<endl<<allTagFlag<<"\nitEnd\n";
    }
    return "contentExtruder: Тег не найден...";
}

void contentExtruder(){
    string in, tag, tagType;
    cout << "Введите файл...\n";
    getline(cin, in);
    cout << "Введите начальный тег...\n";
    getline(cin, tag);
    cout << "Введите тип тега...\n";
    getline(cin, tagType);
    cout << contentExtruder(in, tag, tagType) << endl;
}