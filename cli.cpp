#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int fragment(ifstream& file, int n);
    //cli[0] pack.bin[1] -n[2] 3[3]
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, ".1251");
    // Проверка количества аргументов
    if (argc != 4) {
        cerr << "Ne vernoe kolvo simvolov. Ucpolzovanue: " << argv[0] << "<file.bin> -n <chislo>" << endl;
        return 1;
    }

    // Открытие входного файла
    //
    ifstream inputFile(argv[1], ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Ne otkr file: " << argv[1] << endl;
        return 2;
    }

    // Проверка допустимых меток параметров
    if (string(argv[2]) != "-n"  ) {
        cerr << "nete metki. -n" << endl;
        return 3;
    }

    // Проверка параметров
    int n;
    try {
        n = stoi(string(argv[3]));
    } catch (const invalid_argument& e) {
        cerr << "Oshibka preobrazovanua elimentov: -n" << endl;
        return 4;
    }

    fragment(inputFile, n);
    inputFile.close();
    return 0;
}

int fragment(ifstream& file, int n){
    // Проверка маркера начала заголовка
    char headerMarker[3];
    file.read(headerMarker, 3);
    if (strncmp(headerMarker, "GSE", 3) != 0) {
        throw runtime_error("Не найден маркер заголовка GSE");
    }

    for (int i = 0; i < n; ++i) {
        // Создать имя файла
        string filename = "file" + to_string(i) + ".bin";

        // Открыть файл в двоичном режиме записи
        fstream outfile(filename, ios::out | ios::binary);

        // Проверить, открылся ли файл
        if (outfile.is_open())
        {
            // Записать данные в файл (в данном примере - просто число)
            string data = "GSE";
            outfile.write((char *)&data, sizeof(data));

            // Закрыть файл
            outfile.close();
        }
    }

    char infpok[5];
    //5 байт
    //в конце 12 бит длины пакета
    file.read(infpok, 5);


    
    return 0;
}

// Чтобы скомпилировать, надо в командной строке ввести : g++ cli.cpp -o gse-slice
// Запустить gse-slice icmp_ipv4.bin -n 3 -f 5 -p 0x0800 -t 6  -l 01:02:03:04:05:06 ff:ff:ff
