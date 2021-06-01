#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextStream>
#include <QFile>

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

void MainWindow::on_oblicz_clicked()
{
    float result = 0,a,b;

    a = ui->a->text().toFloat();
    b = ui->b->text().toFloat();
    switch (ui->operacja->currentIndex()){
        case 0:
            result = a+b;
            break;
        case 1:
            result = a-b;
            break;
        case 2:
            result = a*b;
            break;
        case 3:
            if(b == 0){
                ui->wynik->setText("Nie mozna dzielic przez zero!");
                ui->wynik2->setText("Nie mozna dzielic przez zero!");
                return;
            }
            result = a/b;

            break;
    }
    ui->wynik->setText(QString::number(result));
    ui->wynik2->setText(QString::number(result));
}

void MainWindow::on_showAuthor_clicked(bool checked)
{
    if(checked){
        ui->AuthorLabel->setText("Marcin Skic");
    } else {
        ui->AuthorLabel->setText("???");
    }
}

void MainWindow::on_calendarWidget_clicked()
{
    ui->data->setText(ui->calendarWidget->selectedDate().toString());
}

void MainWindow::on_add_surname_button_clicked()
{
    ui->surname_textEdit->append(ui->surname_lineEdit->text());
}

void MainWindow::on_addButton_10_6_clicked()
{
    float currentNumber,total,average;
    bool *isNumber = new bool;
    currentNumber = ui->lineEdit_10_6->text().toFloat(isNumber);

    if(*isNumber){
        ui->list_10_6->addItem(QString::number(currentNumber));
        ui->labelCount_2_10_6->setText("liczba pozycji: "+QString::number(ui->list_10_6->count()));

        total = ui->listTotalValue_10_6->text().toFloat()+currentNumber;
        average = total/ui->list_10_6->count();

        ui->listTotalValue_10_6->setText(QString::number(total));
        ui->labelAverage_10_6->setText("Średnia: "+QString::number(average));
    } else {
        ui->lineEdit_10_6->setText("To nie liczba!");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->list_10_6->clear();
    ui->labelCount_2_10_6->setText("liczba pozycji: ");
    ui->listTotalValue_10_6->setText("0");
    ui->labelAverage_10_6->setText("Średnia: 0");
}

void MainWindow::on_addSpinBoxValue_10_7_clicked()
{
    float currentNumber,total,average;
    currentNumber = ui->spinBox_10_7->value();
    ui->list_10_6->addItem(QString::number(currentNumber));
    ui->labelCount_2_10_6->setText("liczba pozycji: "+QString::number(ui->list_10_6->count()));

    total = ui->listTotalValue_10_6->text().toFloat()+currentNumber;
    average = total/ui->list_10_6->count();

    ui->listTotalValue_10_6->setText(QString::number(total));
    ui->labelAverage_10_6->setText("Średnia: "+QString::number(average));

}

void MainWindow::on_saveToFile_clicked()
{
    QString filename = "notes.txt";
    QFile file(filename);

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << " Could not open file for writing";
        return;
    }

    QTextStream out(&file);
    out<<ui->surname_textEdit->toPlainText();

    file.flush();
    file.close();

}

void MainWindow::on_clearTextEdit_clicked()
{
    ui->surname_textEdit->clear();
}

void MainWindow::on_readFromFile_clicked()
{
    QString filename = "notes.txt";
    QFile file(filename);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << " Could not open the file for reading";
        return;
    }

    QTextStream in(&file);
    QString myText = in.readAll();

    ui->surname_textEdit->setPlainText(myText);

    file.close();
}


void MainWindow::on_redButton_clicked()
{
    if(ui->redButton->isChecked()){
        setStyleSheet("background-color:red");
    }
}

void MainWindow::on_greenButton_clicked()
{
    if(ui->greenButton->isChecked()){
        setStyleSheet("background-color:green");
    }
}

void MainWindow::on_greyButton_clicked()
{
    if(ui->greyButton->isChecked()){
        setStyleSheet("background-color:grey");
    }
}
