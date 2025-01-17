#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    if(argc == 1){
        cout << "Аргументы не введены" << endl;
        return 1;
    }
    cout << "Программа запущена" << endl;
    cout << argc << endl;
    cout << argv[1] << endl;
}