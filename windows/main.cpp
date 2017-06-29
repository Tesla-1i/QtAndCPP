#include "mainwindow.h"
#include <QApplication>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    for(int i=0;i<5;i++)
        cout<<"你好\n";
    std::cout<<"你好啊\n";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
