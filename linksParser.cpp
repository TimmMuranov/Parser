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
  cout << file << endl;
}

string getLinks(string file){
  string linkList = "";
  int fileSize = file.length();
  for(int x=0; x<fileSize; ++x){
    if (file[x] == "\""){
      int end = file.find("\"", x+1);
      if(file.substr(x+1, 4) == "http"){
        linkList += file.substr(x+1, end);
      }
    x += (end - (x+1)) + 1;
    }
  }
}
