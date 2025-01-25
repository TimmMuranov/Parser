//Для работы в режиме библиотеки подключить program/headers.hpp
#include <iostream>
#include <cstring>

#include "program/headers.hpp"
#include "interface/headers.hpp"

using namespace std;

int main(int argc, char *argv[]){
    if(argc == 1){
        startWin();
        err(4);
        return 1;
    }

    if(strcmp(argv[1], "-h") == 0) {
        err(0);
        return 0;
    }

    if(strcmp(argv[1], "-lp") == 0) {
        linksParser();
        return 0;
    }

    if(strcmp(argv[1], "-gth") == 0) {
        getTagHead();
        return 0;
    }

    if(strcmp(argv[1], "-ce") == 0) {
        contentExtruder();
        return 0;
    }
    err(1);
    err(0);
    return 0;
}