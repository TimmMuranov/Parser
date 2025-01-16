// Входные данные:
// "...<tag1 id=1>...</tag>.....<tag2>...</tag2>..."
// "<tag1 id=1>"
//Выходные данные:
// "<tag1 id=1>...</tag1>"

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include "getFileList.hpp"
#include "getFile.hpp"
#include "getTagHead.hpp"

using namespace std;
int main(){
    string path2files = "";
    string path2endFiles = "";
    cout << "Введите полный путь к папке с исходными файлами...\n";
    cin >> path2files;
    cout << "Введите полный путь к папке для сохранения обработаных файлов...\n";
    cin >> path2endFiles;
    vector<string> fl = fileList(path2files);
    int pathSize = fl.size();
    for(int x=0; x<pathSize; ++x){
        fstream f;
        string file = getFile(fl[x]);
        f.open(path2endFiles + "/file " + to_string(x+1), std::fstream::out);
        for(int x=0; x<file.length(); ++x){
            char chFile = file[x];
            //Обработка файла
            f << chFile;
        }
        cout << x+1 << " файл изменен и записан." << endl;
        f.close();
    }
    cout << "Все файлы в папке выведены." << endl;
}
