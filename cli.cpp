#include <iostream>

int main(int argc, char* argv[]) {
    // Проверка количества аргументов
    if (argc != 2) {
        std::cerr << "Ошибка: Необходимо указать текст для записи." << std::endl;
        return 1;
    }

    // Получение текста из аргумента
    std::string text = argv[1];

    // Запись текста в консоль
    std::cout << "Записано: " << text << std::endl;

    return 0;
}
 ГОВНО НЕ РАБОТАЕТ!
