#include "mainwindow.h"
#include <QApplication>
#include "model.h"
#include "sterowanie.h"
#include "wyswietlanie.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Model model;
    Sterowanie sterowanie;
    Wyswietlanie wyswietlanie;

    wyswietlanie.podlaczModel(&model);

    QObject::connect(sterowanie.przycisk(),
                     SIGNAL (clicked()),
                     &app,
                     SLOT(quit())
                     );
    QObject::connect(sterowanie.slidera(),
                     SIGNAL (valueChanged (int)),
                     &wyswietlanie,
                     SLOT(przerysuj(int))
                     );
    wyswietlanie.show();
    sterowanie.show();

    return app.exec();
}
