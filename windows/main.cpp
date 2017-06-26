#include "mainwindow.h"
#include <QApplication>
#include<iostream>

int main(int argc, char *argv[])
{
    std::cout<<"你好啊\n";
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
