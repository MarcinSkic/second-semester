#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit_2->setText(ui->lineEdit->text());
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    int promien = ui->promien->text().toInt();
    int wynik = 2*promien;
    ui->wynik->setText(QString::number(wynik));
}
