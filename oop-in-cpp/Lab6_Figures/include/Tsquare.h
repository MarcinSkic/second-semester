#ifndef TSQUARE_H
#define TSQUARE_H
#include "Tfigure.h"
#include <string>

using namespace std;

class Tsquare : public Tfigure  //Teoretycznie mozna dziedziczyc po prostokacie i w miejsce zmiennych a i b wstawic to samo i korzystac z metod prostokata ale wtedy mamy
{                               //o jedna zmienna wiecej niz potrzeba
    public:
        Tsquare();
        Tsquare(string name, float a);
        virtual ~Tsquare();
        void draw();
        float calculateArea();
        float calculatePerimeter();
    protected:
        float a;
    private:
};

#endif // TSQUARE_H
