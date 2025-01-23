#include <iostream>
#include <string>
#include <fstream>
#include "help.h"
using namespace std;

void err(int errNum){
    switch(errNum){
        case 0:{
            cout << help << endl;
            return;
        }
        case 1:{
            cout << "Команда не найдена..." << endl;
            return;
        }
        case 2:{
            cout << "Аргументы не введены..." << endl;
            return;
        } 
        case 3:{
            cout << "'startParser help' чтобы узнать доступные команды" << endl;
        }
    }
}