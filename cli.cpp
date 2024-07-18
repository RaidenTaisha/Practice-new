#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

// Описание структуры GSE-заголовка
struct GSEHeader {
    uint8_t version;             // Версия протокола GSE (0x01)
    uint8_t protocol;           // Протокол инкапсуляции (UDP, TCP, ICMP, etc.)
    uint16_t sequenceNumber;    // Номер последовательности
    uint16_t fragmentId;        // ID фрагмента
    uint16_t fragmentCount;     // Общее количество фрагментов
    uint16_t timestamp;         // Метка времени (3 или 6 байтов)
    uint8_t flags;              // Флаги (0x00)
    uint8_t padding;            // Заполнение (0x00)
};

// Функция фрагментации сетевого пакета
void fragmentPacket(const string& inputFile, int n, int f, unsigned int p, int t, const string& l) {
    // Открытие входного файла
    ifstream inputFileStream(inputFile, ios::binary);
    if (!inputFileStream.is_open()) {
        cerr << "Не удалось открыть файл: " << inputFile << endl;
        return;
    }

    // Проверка размера пакета
    inputFileStream.seekg(0, ios::end);
    int packetSize = static_cast<int>(inputFileStream.tellg());
    inputFileStream.seekg(0, ios::beg);

    // Вычисление параметров фрагментации
    int fragmentLength = packetSize / n;
    int remainder = packetSize % n;

    // Чтение и фрагментация пакета
    vector<char> buffer(fragmentLength + 1);
    for (int i = 0; i < n; ++i) {
        // Чтение фрагмента
        inputFileStream.read(buffer.data(), fragmentLength);

        // Создание GSE-заголовка
        GSEHeader header;
        header.version = 0x01;
        header.protocol = p;
        header.sequenceNumber = i;
        header.fragmentId = f;
        header.fragmentCount = n;

        // Конвертация метки времени из строки в массив байтов
        vector<uint8_t> timestampBytes;
        if (t == 3) {
            for (const char& c : l) {
                if (isdigit(c)) {
                    timestampBytes.push_back(static_cast<uint8_t>(c - '0'));
                } else if (c == ':') {
                    // Проверка правильности формата метки времени
                    if (timestampBytes.size() != 2) {
                        cerr << "Неверный формат метки времени: " << l << endl;
                        return;
                    }
                    timestampBytes.clear();
                } else {
                    cerr << "Неверный формат метки времени: " << l << endl;
                    return;
                }
            }
            if (timestampBytes.size() != 2) {
                cerr << "Неверный формат метки времени: " << l << endl;
                return;
            }
        } else if (t == 6) {
            for (const char& c : l) {
                if (isdigit(c)) {
                    timestampBytes.push_back(static_cast<uint8_t>(c - '0'));
                } else if (c == ':') {
                    // Проверка правильности формата метки времени
                    if (timestampBytes.size() != 5) {
                        cerr << "Неверный формат метки времени: " << l << endl;
                        return;
                    }
                    timestampBytes.clear();
                } else {
                    cerr << "Неверный формат метки времени: " << l << endl;
                    return;
                }
            }
            if (timestampBytes.size() != 5) {
                cerr << "Неверный формат метки времени: " << l << endl;
                return;
            }
        } else {
            cerr << "Неверный размер метки времени: " << t << " байт" << endl;
            return;
        }

        header.timestamp = timestampBytes[0] << 24 | timestampBytes[1] << 16 | timestampBytes[2] << 8 | timestampBytes[3];
        header.flags = 0x00;
        header.padding = 0x00;

        // Создание имени выходного файла
        string outputFileName = string(inputFile.substr(0, inputFile.size() - 4)) + "_" + to_string(i) + ".bin";

        // Открытие выходного файла
        ofstream outputFileStream(outputFileName, ios::binary);
        if (!outputFileStream.is_open()) {
            cerr << "Не удалось открыть файл: " << outputFileName << endl;
            return;
        }

        // Запись GSE-заголовка в выходной файл
        outputFileStream.write(reinterpret_cast<char*>(&header), sizeof(GSEHeader));

        // Запись фрагмента пакета в выходной файл
        outputFileStream.write(buffer.data(), fragmentLength);

        // Закрытие выходного файла
        outputFileStream.close();
    }

    // Запись оставшегося фрагмента (если есть)
    if (remainder > 0) {
        buffer.resize(remainder);
        inputFileStream.read(buffer.data(), remainder);

        // Создание GSE-заголовка
        GSEHeader header;
        header.version = 0x01;
        header.protocol = p;
        header.sequenceNumber = n - 1;
        header.fragmentId = f;
        header.fragmentCount = n;

        // Конвертация метки времени из строки в массив байтов
        vector<uint8_t> timestampBytes;
        if (t == 3) {
            for (const char& c : l) {
                if (isdigit(c)) {
                    timestampBytes.push_back(static_cast<uint8_t>(c - '0'));
                } else if (c == ':') {
                    // Проверка правильности формата метки времени
                    if (timestampBytes.size() != 2) {
                        cerr << "Неверный формат метки времени: " << l << endl;
                        return;
                    }
                    timestampBytes.clear();
                } else {
                    cerr << "Неверный формат метки времени: " << l << endl;
                    return;
                }
            }
            if (timestampBytes.size() != 2) {
                cerr << "Неверный формат метки времени: " << l << endl;
                return;
            }
        } else if (t == 6) {
            for (const char& c : l) {
                if (isdigit(c)) {
                    timestampBytes.push_back(static_cast<uint8_t>(c - '0'));
                } else if (c == ':') {
                    // Проверка правильности формата метки времени
                    if (timestampBytes.size() != 5) {
                        cerr << "Неверный формат метки времени: " << l << endl;
                        return;
                    }
                    timestampBytes.clear();
                } else {
                    cerr << "Неверный формат метки времени: " << l << endl;
                    return;
                }
            }
            if (timestampBytes.size() != 5) {
                cerr << "Неверный формат метки времени: " << l << endl;
                return;
            }
        } else {
            cerr << "Неверный размер метки времени: " << t << " байт" << endl;
            return;
        }

        // Заполнение GSE-заголовка
        header.timestamp = timestampBytes[0] << 24 | timestampBytes[1] << 16 | timestampBytes[2] << 8 | timestampBytes[3];
        header.flags = 0x00;
        header.padding = 0x00;

        // Создание имени выходного файла
        string outputFileName = string(inputFile.substr(0, inputFile.size() - 4)) + "_" + to_string(n - 1) + ".bin";

        // Открытие выходного файла
        ofstream outputFileStream(outputFileName, ios::binary);
        if (!outputFileStream.is_open()) {
            cerr << "Не удалось открыть файл: " << outputFileName << endl;
            // Запись GSE-заголовка в выходной файл
            outputFileStream.write(reinterpret_cast<char*>(&header), sizeof(GSEHeader));

            // Запись фрагмента пакета в выходной файл
            outputFileStream.write(buffer.data(), remainder);

            // Закрытие выходного файла
            outputFileStream.close();
        }

        // Закрытие входного файла
        inputFileStream.close();
    }
}

int cli(int argc, char* argv[]) {
    setlocale(LC_ALL, ".1251");
    // Проверка количества аргументов
    if (argc != 12) {
        cerr << "Ne vernoe kolvo simvolov. Ucpolzovanue: " << argv[0] << " -n <chislo> -f <chislo> -p <16-oe chislo> <vzodnoi file>" << endl;
        return 1;
    }

    // Проверка параметров
    int n,f,t;
    string l;
    unsigned int p;

    try {
        n = stoi(string(argv[3]));
        f = stoi(string(argv[5]));
        p = stoul(string(argv[7]), nullptr, 16);
        t = stoi(string(argv[9]));
        l = stoi(string(argv[11]));
    } catch (const invalid_argument& e) {
        cerr << "Oshibka preobrazovanua elimentov. -n, -f and -p ." << endl;
        return 1;
    }

    // Проверка допустимых меток параметров
    if (string(argv[2]) != "-n" || string(argv[4]) != "-f" || string(argv[6]) != "-p" || string(argv[9]) != "-t" || string(argv[11]) != "-l") {
        cerr << "nete metki. -n, -f and -p." << endl;
        return 1;
    }

    // Открытие входного файла
    ifstream inputFile(argv[1], ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Ne otkr file: " << argv[1] << endl;
        return 1;
    }

    fragmentPacket(argv[1], n, f, p, t, l);

    inputFile.close();

    return 0;
}

// Чтобы скомпилировать, надо в командной строке ввести : g++ cli.cpp -o gse-slice
// Запустить gse-slice icmp_ipv4.bin -n 3 -f 5 -p 0x0800 -t 6  -l 01:02:03:04:05:06
