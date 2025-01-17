#include <iostream>
#include <fstream>
#include <string>

#pragma once

using namespace std;

void linksParser(){
  string file;
  string fileName;
  cout << "Введите имя файла...\n";
  getline(cin, fileName);
  ifstream in(fileName);
  if (in.is_open()){
      string line;
      while (getline(in, line)){
            file += line;
        }
  }
  in.close();
  //cout << "Исходный файл: " << endl << file << endl;

/////////////////////////////////////////////////
  cout <<"Парсинг ссылок начинается...\n";
  string linkList = "";
  bool flag = 0;
  bool flagWrite = 0;
  for(int x=0; x<file.length(); ++x){
    if(file[x] == '"'){
      if(!flag){
        flag = 1;
        //cout << x + 1 << " ";
      }
      else{
        flag = 0;
        //cout << x - 1 << endl;
        if(flagWrite){
          linkList += "\n";
          flagWrite = 0;
        }
        else flagWrite = 0;
      }
    }
    if(file.substr(x, 4) == "http") flagWrite = 1;
    if(flag && flagWrite){
      if(file[x] != '"'){
        linkList += file[x];
      }
    }
  }
  cout << linkList;
}
