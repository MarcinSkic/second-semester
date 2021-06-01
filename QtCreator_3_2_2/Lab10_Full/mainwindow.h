#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_oblicz_clicked();

    void on_showAuthor_clicked(bool checked);

    void on_calendarWidget_clicked();

    void on_add_surname_button_clicked();

    void on_addButton_10_6_clicked();

    void on_pushButton_2_clicked();

    void on_addSpinBoxValue_10_7_clicked();

    void on_saveToFile_clicked();

    void on_clearTextEdit_clicked();

    void on_readFromFile_clicked();

    void on_redButton_clicked();

    void on_greenButton_clicked();

    void on_greyButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
