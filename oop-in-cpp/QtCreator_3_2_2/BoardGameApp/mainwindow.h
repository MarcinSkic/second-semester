#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "marsgame.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void WondersCalculateScore();
    void UpdateInstructions();
    void NextInstruction();
    void AddToHistory();
    ~MainWindow();

private slots:


    void on_writingSpingBox_editingFinished();

    void on_mathSpinBox_editingFinished();

    void on_engineeringSpinBox_editingFinished();

    void on_activateButton_clicked();

    void on_continueInstructionButton_clicked();

private:
    Ui::MainWindow *ui;
    marsGame *currentGame;
    bool isActionPhase;

};

#endif // MAINWINDOW_H
