#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
// Самодельная структура байта для работы с побитовыми операциями
struct sByte
{
    unsigned int b0;
    unsigned int b1;
    unsigned int b2;
    unsigned int b3;
    unsigned int b4;
    unsigned int b5;
    unsigned int b6;
    unsigned int b7;
};

char getCharByBit(sByte data);
int binary_to_decimal(string binary_string);
int fragment(ifstream &file, int n);
sByte getByteInBit(char data);

// cli[0] pack.bin[1] -n[2] 3[3] пример запуска
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, ".1251");
    // Проверка количества аргументов
    if (argc != 4)
    {
        cerr << "Ne vernoe kolvo simvolov. Ucpolzovanue: " << argv[0] << "<file.bin> -n <chislo>" << endl;
        return 1;
    }

    // Открытие входного файла
    //
    ifstream inputFile(argv[1], ios::binary);
    if (!inputFile.is_open())
    {
        cerr << "Ne otkr file: " << argv[1] << endl;
        return 2;
    }

    // Проверка допустимых меток параметров
    if (string(argv[2]) != "-n")
    {
        cerr << "nete metki. -n" << endl;
        return 3;
    }

    // Проверка параметров
    int n;
    try
    {
        n = stoi(string(argv[3]));
    }
    catch (const invalid_argument &e)
    {
        cerr << "Oshibka preobrazovanua elimentov: -n" << endl;
        return 4;
    }
    // фрагментация пакета
    fragment(inputFile, n);
    inputFile.close();
    return 0;
}

int fragment(ifstream &file, int n)
{
    // Проверка маркера начала заголовка
    /*TODO char headerMarker[3];
    file.read(headerMarker, 3);
    if (strncmp(headerMarker, "GSE", 3) != 0)
    {
        throw runtime_error("Не найден маркер заголовка GSE");
    }*/

    // Считываем три байта из фалйа, где первые 4 бита это метки S-1бит, E-1бит и L-2бит + 12бит GSE lenght + 8бит Frag ID
    char head[3];
    file.read(head, 3);
    sByte data0 = getByteInBit(head[0]);
    sByte data1 = getByteInBit(head[1]);
    sByte data2 = getByteInBit(head[2]);

    // 12 бит забираем в строку, что бы преобразовать в нормальное число ( нам его делить на общее кол-во фрагментов)
    string s = "" + to_string(data0.b4) + to_string(data0.b5) + to_string(data0.b6) + to_string(data0.b7) + to_string(data1.b0) + to_string(data1.b1) + to_string(data1.b2) + to_string(data1.b3) + to_string(data1.b4) + to_string(data1.b5) + to_string(data1.b6) + to_string(data1.b7);

    // переделываем безобразие в нормальное число
    int k = binary_to_decimal(s); // кол-во байт в GSE

    // проверяем, можем ли мы сделать фрагментацию
    if (k < n * 2 || n < 1)
    {
        cerr << "net smisla v fragmentasii, kolvo bayt = " << k << " kolvo fragmentov = " << n;
        exit(5);
    }

    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            // метки S, E, LT для первого пакета
            data0.b0 = 1;
            data0.b1 = 0;
            data0.b2 = 0;
            data0.b3 = 0;
        }
        else if (i == (n - 1))
        {
            // метки S, E, LT для последнего пакета
            data0.b0 = 0;
            data0.b1 = 1;
            data0.b2 = 1;
            data0.b3 = 1;
        }
        else
        {
            // метки S, E, LT для остальных
            data0.b0 = 0;
            data0.b1 = 0;
            data0.b2 = 1;
            data0.b3 = 1;
        }
        // Создаем путик файлика
        string filename = "file" + to_string(i) + ".bin";

        // создать и открыть их
        ofstream outfile(filename, ios::binary);

        // Проверочка
        if (!outfile.is_open())
        {
            cerr << "ne otkrilis fali blyad";
            exit(6);
        }

        // собираем все 3 байта начального заголовка ( которые чутка подправили и есть у всех пакетов) в массив и шлем их в пакеты
        char chdata[3] = {getCharByBit(data0), getCharByBit(data1), getCharByBit(data2)};

        // Записываем GSE метку заголовка и сам заголовок
        //TODO outfile.write(headerMarker, sizeof(headerMarker));
        outfile.write(chdata, sizeof(chdata));
        // закрываем фалики, так как надо их потом заново открывать
        outfile.close();
    }

    int t = 3;
    // определяем кол-во байтов которые нада распределить по п`окетам
    int sizeOfPack = k / n;
    int lastsize = sizeOfPack + k % n;
    for (int i = 0; i < n; ++i)
    {
        // Создаем путик файлика
        string filename = "file" + to_string(i) + ".bin";

        //открыть их
        ofstream outfile(filename, ios::ate | ios::binary);

        // Проверочка
        if (!outfile.is_open())
        {
            cerr << "ne otkrilis fali blyad";
            exit(8);
        }

        // Если n первый пакет, то записываем поля полей total lenth 2байта, protocol type 2байта, label 3байта или 6байт и sizeofpack, если последний, то lastsize + конец, остальные sizeofpack
        if (i == 0)
        {
            // Для первого пакета
            char data[4 + t + sizeOfPack];
            file.read(data, 4 + t + sizeOfPack);
            outfile.write(data, 4 + t + sizeOfPack);
        }
        else if (i == n - 1)
        {
            // Для последнего
            char data[lastsize + 4];
            file.read(data, lastsize + 4);
            outfile.write(data, lastsize + 4);
        }
        else
        {
            // Для остальных
            char data[sizeOfPack];
            file.read(data, sizeOfPack);
            outfile.write(data, sizeOfPack);
        }

        // Закрытие файлов
        outfile.close();
    }

    return 0;
}

//биты из Байта
sByte getByteInBit(char data)
{
    sByte b;
    b.b0 = (data >> 0) & 1;
    b.b1 = (data >> 1) & 1;
    b.b2 = (data >> 2) & 1;
    b.b3 = (data >> 3) & 1;
    b.b4 = (data >> 4) & 1;
    b.b5 = (data >> 5) & 1;
    b.b6 = (data >> 6) & 1;
    b.b7 = (data >> 7) & 1;
    return b;
}

//Байт из битов
char getCharByBit(sByte data)
{
    char ch = stoi("0b" + to_string(data.b0) + to_string(data.b1) + to_string(data.b2) + to_string(data.b3) + to_string(data.b4) + to_string(data.b5) + to_string(data.b6) + to_string(data.b7));

    return ch;
}

// Из двоичного в десятичное
int binary_to_decimal(string binary_string)
{
    int decimal_value = 0;
    int base = 1;

    // Проходим по строке в обратном порядке
    for (int i = binary_string.length() - 1; i >= 0; i--)
    {
        if (binary_string[i] == '1')
        {
            decimal_value += base;
        }
        base *= 2;
    }

    return decimal_value;
}

// Чтобы скомпилировать, надо в командной строке ввести : g++ cli.cpp -o gse-slice
// Запустить gse-slice icmp_ipv4.bin -n 3 -f 5 -p 0x0800 -t 6  -l 01:02:03:04:05:06 ff:ff:ff
