#include <iostream>
#include <string>
#include "help.h"

using namespace std;

void err(int errNum){
    switch(errNum){
        case 0:{
            cout << comands << endl;
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
            cout << "'startParser -h' чтобы узнать доступные команды" << endl;
            return;
        }
        case 4:{
            cout << help << endl;
            return;
        }
    }
}
