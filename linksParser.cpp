#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
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
