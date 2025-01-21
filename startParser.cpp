#include <iostream>
#include <cstring>

#include "program/headers.hpp"
#include "interface/headers.hpp"

using namespace std;

int main(int argc, char *argv[]){
    if(argc == 1){
        cout << "Аргументы не введены" << endl;
        cout << "Доступные команды: linksParser getTagHead" << endl;
        return 1;
    }

    if(strcmp(argv[1], "linksParser") == 0) {
        linksParser();
        return 0;
    }

    if(strcmp(argv[1], "getTagHead") == 0) {
        getTagHead();
        return 0;
    }

    if(strcmp(argv[1], "contentExtruder") == 0) {
        contentExtruder();
        return 0;
    }

    cout << argv[1] << " - "<< "Команда не нейдена..." << endl;
    cout << "Доступные команды: linksParser getTagHead" << endl;
    return 1;
}