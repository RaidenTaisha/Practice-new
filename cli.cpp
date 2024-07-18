#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;



int main(int argc, char* argv[]) {
    setlocale(LC_ALL, ".1251");
    // Проверка количества аргументов
    if (argc != 4) {
        cerr << "Ne vernoe kolvo simvolov. Ucpolzovanue: " << argv[0] << " -n <chislo> -f <chislo> -p <16-oe chislo> <vzodnoi file>" << endl;
        return 1;
    }

    // Проверка параметров
    int n,f,t;
    string l;
    unsigned int p;

    try {
        n = stoi(string(argv[3]));
        //f = stoi(string(argv[5]));
        //p = stoul(string(argv[7]), nullptr, 16);
        //t = stoi(string(argv[9]));
        //l = stoi(string(argv[11]));
    } catch (const invalid_argument& e) {
        cerr << "Oshibka preobrazovanua elimentov. -n, -f and -p ." << endl;
        return 1;
    }
    //|| string(argv[4]) != "-f" || string(argv[6]) != "-p"|| string(argv[8]) != "-t" || string(argv[10]) != "-l"
    // Проверка допустимых меток параметров
    if (string(argv[2]) != "-n"  ) {
        cerr << "nete metki. -n, -f and -p." << endl;
        return 1;
    }

    // Открытие входного файла
    ifstream inputFile(argv[1], ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Ne otkr file: " << argv[1] << endl;
        return 1;
    }



    inputFile.close();

    return 0;
}

// Чтобы скомпилировать, надо в командной строке ввести : g++ cli.cpp -o gse-slice
// Запустить gse-slice icmp_ipv4.bin -n 3 -f 5 -p 0x0800 -t 6  -l 01:02:03:04:05:06 ff:ff:ff
