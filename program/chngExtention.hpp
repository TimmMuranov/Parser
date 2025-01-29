 #include <iostream>
#include <fstream>
#include <string>

using namespace std;

string chngExtention(string n, string e){
    if(e[0] != '.'){
        e = '.' + e;
    }
    if(n.find_last_of('.') != string::npos){
        return n.substr(0, n.find_last_of('.')) + e;
    } else {
        return n + e;
    }
}

void chngExtention(){
  string name;
  string ext;
  cout << "Введите имя...\n";
  cin >> name;
  cout << "Введите новое расширение...\n";
  cin >> ext;
  cout << chngExtention(name, ext) << endl;
}
