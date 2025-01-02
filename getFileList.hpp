#include <string>
#include <filesystem>

// Функция для получения списка файлов в папке
std::string fileList(const std::string& path) {
    std::string answer;

    // Проверяем, существует ли указанный путь и является ли он директорией
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
        // Перебираем файлы в указанной директории
        for (const auto& entry : std::filesystem::directory_iterator(path)) {
            // Добавляем имя файла/каталога в результат
            answer += entry.path().filename().string() + "\n";
        }
    }
    return answer;
}
