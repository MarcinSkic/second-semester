#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include "marsgame.h"
#include <QThread>
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

void MainWindow::WondersCalculateScore(){
    int min = 0;
    int totalScore = 0;
    if(ui->writingSpingBox->value() < ui->engineeringSpinBox->value()){
        min = ui->writingSpingBox->value();
    } else {
        min = ui->engineeringSpinBox->value();
    }
    if(min > ui->mathSpinBox->value()){
        min = ui->mathSpinBox->value();
    }
    totalScore += min*7;
    totalScore += pow(ui->writingSpingBox->value(),2);
    totalScore += pow(ui->engineeringSpinBox->value(),2);
    totalScore += pow(ui->mathSpinBox->value(),2);
    ui->totalScoreLineEdit->setText(QString::number(totalScore));
}
void MainWindow::UpdateInstructions(){
    ui->phasesLabel->setText(currentGame->getPhase());
    ui->instructionLineEdit->setText(currentGame->getInstruction());
}
void MainWindow::NextInstruction(){
    AddToHistory();

    int progressValue;
    currentGame->pressedNextInstruction(isActionPhase,progressValue);
    ui->turnProgressBar->setValue(progressValue);
    if(isActionPhase){
        ui->extraChoice->setEnabled(true);
    } else {
        ui->extraChoice->setEnabled(false);
    }
    if(progressValue == 0){
        ui->historyOfTurns->addItem("Tura "+QString::number(currentGame->GetTurn()));
    }
    UpdateInstructions();

}
void MainWindow::AddToHistory(){
    if(isActionPhase){
        ui->historyOfTurns->addItem("Gracz: "+ui->extraChoice->currentText());
        return;
    }
    ui->historyOfTurns->addItem("Gracz: "+currentGame->getInstruction());
}

void MainWindow::on_writingSpingBox_editingFinished()
{
    WondersCalculateScore();
}

void MainWindow::on_mathSpinBox_editingFinished()
{
    WondersCalculateScore();
}

void MainWindow::on_engineeringSpinBox_editingFinished()
{
    WondersCalculateScore();
}

void MainWindow::on_activateButton_clicked()
{

    currentGame = new marsGame;
    ui->historyOfTurns->clear();
    ui->turnProgressBar->setValue(0);

    ui->historyOfTurns->addItem("Tura 1");
    NextInstruction();
}

void MainWindow::on_continueInstructionButton_clicked()
{
    NextInstruction();
}

