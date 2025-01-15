//Читает содержимое файла в данной директории
#include <string>
#include <fstream>
#include <filesystem>

std::string getFile (const std::string &name) {
    std::string f = "";
    std::ifstream in(name);
        if (in.is_open()){
            std::string line;
            while (getline(in, line)){
                f += line;
            }
        }
    in.close();
    return f;
}
