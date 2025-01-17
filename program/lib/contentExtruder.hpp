#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#pragma once

using namespace std;
namespace fs = std::filesystem;

void contentExtruder(){
    fstream f;
    string file;
    string path;
    string endPath;
    string startDiv;
    cout << "Читает html-страницы из указанной папки, извлекает содержимое указанного div тега и сохраняет извлеченное во вторую указанную папку.\n";
    cout << "При нескольких одинаковых div-тегах вход/выход происходит по первому встреченному в файле тегу\n";
    cout << "Файлы по одиночке не обрабатывает. Это можно сделать и руками :)\n";
    cout << "Введите полное имя папки с файлами для обработки...\n";
    cin >> path;
    cout << "Введите div тег со скобками и всеми его спецификаторами (id, name, class,..)" << endl;
    cin >> startDiv;
    cout << "Введите полное имя папки для записи...\n";
    cin >> endPath;
    cout << endl;
    for (const auto& entry : fs::directory_iterator(path)){
        string firstFileRoad = entry.path();
        ifstream in(firstFileRoad);
        if (in.is_open()){
            string line;
            while (getline(in, line)){
                file += line;
            }
        }
        in.close();
//========================================================
        bool openDivFlag = 0;
        int allDivFlag = 0;
        int size = file.length();
        string finFile = "";
        for(int x=0; x<size; ++x){
            if(file.substr(x, startDiv.length()) == startDiv){
                cout << "Точка вхожденя найдена: " << x << endl;
                openDivFlag = 1;
                x += 9;
            }
            if(file.substr(x+1, 5) == "<div>") ++allDivFlag;
            if(file.substr(x+1, 6) == "</div>") --allDivFlag;
            if(openDivFlag) finFile += file[x];
            if(file.substr(x+1, 6) == "</div>" && !allDivFlag){
                cout << "Точка выхода найдена: " << x << endl;
                openDivFlag = 0;
                break;
            }
        }

        string fileName = firstFileRoad.substr(firstFileRoad.rfind("/")) + ".html";
        f.open(endPath + fileName, std::fstream::out);
        f << finFile;
        cout << "Файл " << firstFileRoad << " обновлен!\n";
        cout << firstFileRoad << " записан в " << endPath << " " << std::endl;
        file = "";
        finFile = "";
        f.close();
    }
}
