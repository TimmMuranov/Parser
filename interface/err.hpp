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
            cout << "'startParser -h' для получения информации" << endl;
            cout << "'startParser -c' для просмотра комманд консоли" << endl;
            return;
        }
        case 4:{
            startWin();
            cout << help << endl;
            return;
        }
    }
}

void err(string in){
    if (in == "-h"){
        cout << help_h << endl;
    } else if (in == "-c"){
        cout << help_c << endl;
    } else if (in == "-lp"){
        cout << help_lp << endl;
    } else if (in == "-gth"){
        cout << help_gth << endl;
    } else if (in == "-ce"){
        cout << help_ce << endl;
    } else if (in == "-che"){
        cout << help_che << endl;
    } else {
        cout << "По команде " << in << " нет результатов...\n";
    }
}
