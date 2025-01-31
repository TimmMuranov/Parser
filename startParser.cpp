//Для работы в режиме библиотеки подключить program/headers.hpp
#include <iostream>
#include <cstring>

#include "program/headers.hpp"
#include "interface/headers.hpp"

using namespace std;

int main(int argc, char *argv[]){
    if(argc == 1){
        startWin();
        err(3);
        return 1;
    }

    if(argc == 3){
        if(strcmp(argv[2], "-h") == 0){
            err(argv[1]);
            return 0;
        }
    }

    if(strcmp(argv[1], "-c") == 0) {
        err(0);
        return 0;
    }

    if(strcmp(argv[1], "-h") == 0) {
        err(4);
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

    if(strcmp(argv[1], "-che") == 0) {
        chngExtention();
        return 0;
    }

    if(strcmp(argv[1], "-tr") == 0) {
        tagRemove();
        return 0;
    }

    err(1);
    return 0;
}
