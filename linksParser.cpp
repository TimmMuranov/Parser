#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
  string file;
  string fileName;
  cout << "Введите имя файла\n";
  cin >> fileName;
    ifstream in(fileName);
    if (in.is_open()){
      string line;
      while (getline(in, line)){
            file += line;
        }
    }
  in.close();
  cout <<"Парсинг ссылок начинается...\n"
  cout << getLinks(file) << endl;
}

string getLinks(string f){
  string linkList = "";
  int fileSize = f.length();
  for(int x=0; x<fileSize; ++x){
    if (f[x] == "\""){
      int end = f.find("\"", x+1);
      if(f.substr(x+1, 4) == "http"){
        linkList += f.substr(x+1, end);
      }
    x += (end - (x+1)) + 1;
    }
  }
}
