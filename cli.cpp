#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, ".1251");
    // Проверка количества аргументов
    if (argc != 8) {
        cerr << "Ne vernoe kolvo simvolov. Ucpolzovanue: " << argv[0] << " -n <chislo> -f <chislo> -p <16-oe chislo> <vzodnoi file>" << endl;
        return 1;
    }

    // Проверка параметров
    int n;
    int f;
    unsigned int p;

    try {
        n = stoi(string(argv[3]));
        f = stoi(string(argv[5]));
        p = stoul(string(argv[7]), nullptr, 16);
    } catch (const invalid_argument& e) {
        cerr << "Oshibka preobrazovanua elimentov. -n, -f and -p ." << endl;
        return 1;
    }

    // Проверка допустимых меток параметров
    if (string(argv[2]) != "-n" || string(argv[4]) != "-f" || string(argv[6]) != "-p") {
        cerr << "nete metki. -n, -f and -p." << endl;
        return 1;
    }

    // Открытие входного файла
    ifstream inputFile(argv[1], ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Ne otkr file: " << argv[1] << endl;
        return 1;
    }

    // // Получение размера файла
    // streamsize fileSize = inputFile.seekg(0, ios::end);
    // inputFile.seekg(0, ios::beg);

    // // Проверка, кратен ли размер файла размеру фрагмента
    // if (fileSize % f != 0) {
    //     cerr << "Размер файла не кратен размеру фрагмента." << endl;
    //     return 1;
    // }

    // Обработка файла
    //for (int i = 0; i < n; ++i) {
    //    char buffer[f];
   //    inputFile.seekg(i * f + p);
    //    inputFile.read(buffer, f);

        // Вывод фрагмента на экран
    //    for (int j = 0; j < f; ++j) {
    //        cout << buffer[j];
    //    }
    //}

    cout <<"ZAPISALO"<<" "<< n <<" "<< f <<" "<< p << endl;
    inputFile.close();

    return 0;
}


// Чтобы скомпилировать, надо в командной строке ввести : g++ cli.cpp -o gse-slice
// Запустить gse-slice icmp_ipv4.bin -n 3 -f 5 -p 0x0800



//-t 6 01:02:03:04:05:06
