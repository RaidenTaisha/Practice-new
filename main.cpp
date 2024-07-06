#include "mainwindow.h"
#include <string>
#include <QApplication>
using namespace std;
int main(int argc, char *argv[])
{

    string str = "Баженблять";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
