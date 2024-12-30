//Вырезает все что не входит в блок <article>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main(){
    fstream f;
    string file;
    string path;
    string endPath;
    cout << "Введите полное имя папки с файлами для обработки...\n";
    cin >> path;
    cout << "Введите полное имя папки для записи...\n";
    cin >> endPath;
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
            if(file.substr(x, 9) == "<article>"){
                cout << "Точка вхожденя найдена: " << x << endl;
                openDivFlag = 1;
                x += 9;
            }
            if(openDivFlag) finFile += file[x];
            if(file.substr(x+1, 10) == "</article>"){
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
