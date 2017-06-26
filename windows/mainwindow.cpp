#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText(tr("你好世界,你好世界"));//标点符号必须英文
}

MainWindow::~MainWindow()
{
    delete ui;
}
