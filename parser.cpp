#include <iostream>

using namespace std;

int main(int argc = 0, char *argv[]){
    if(argc == 0){
        cout << "Аргументы не введены" << endl;
        return 1;
    }
    cout << "Программа запущена";
}