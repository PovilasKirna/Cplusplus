#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <main.cpp>
#include <string>
#include <fstream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

string ivestis="";
string isvestis="";

void getivestis(string filename){
    ifstream fin(filename);
    int i = 0;
    for(i; fin.eof()!=true ; i++)
      ivestis += fin.get();
    i--;
    ivestis.erase(ivestis.end()-1);
    ivestis+="\n";
    ivestis+="\n";
    fin.close();
}

void getisvestis(string filename){
    ifstream fin(filename);
    int i = 0;
    for(i; fin.eof()!=true ; i++)
      isvestis += fin.get();
    i--;
    isvestis.erase(isvestis.end()-1);
    fin.close();
}

void MainWindow::on_pushButton_clicked()
{
    run();
    getivestis("/Users/Povilas/Documents/GitHub/Cplusplus/ND5-13/inputV.txt");
    getivestis("/Users/Povilas/Documents/GitHub/Cplusplus/ND5-13/inputZ.txt");
    getisvestis("/Users/Povilas/Documents/GitHub/Cplusplus/ND5-13/cmake-build-debug/output.txt");
    ui->label_1->setText(QString::fromStdString(ivestis));
    ui->label_3->setText(QString::fromStdString(isvestis));
}
