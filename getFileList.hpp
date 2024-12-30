//Принимает полный путь к папке и возвращает вектор из названий всего содержимого.
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

std::vector<std::string> fileList(const std::string &path) {
    if (!fs::exists(path)) {
        return {"Директория не найдена."};
    }
    std::vector<std::string> files;
    for (const auto &entry : fs::directory_iterator(path)) {
        files.push_back(entry.path().u8string()); // Добавляем путь к файлу в вектор
    }
    return files;
}

//Пример использования
//int main() {
//     std::string path = "path/to/dir/";
//     std::vector<std::string> result = fileList(path);
//
//     if (result.size() == 1 && result[0] == "Директория не найдена.") {
//         std::cerr << result[0] << std::endl;
//     } else {
//         for (const auto &file : result) {
//             std::cout << file << std::endl;
//         }
//     }
//     return 0;
// }

