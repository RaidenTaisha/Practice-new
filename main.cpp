#include "mainwindow.h"
#include <QApplication>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//получение сигнала с окна
// выполнить дефрагментацию
//проверить файл
//считать файл
//разделить
    return a.exec();
}
