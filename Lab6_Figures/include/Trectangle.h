#ifndef TRECTANGLE_H
#define TRECTANGLE_H
#include "Tfigure.h"
#include <string>

class Trectangle : public Tfigure
{
    public:
        Trectangle();
        Trectangle(string name, float a, float b);
        virtual ~Trectangle();
        void draw();
        float calculateArea();
        float calculatePerimeter();

    protected:
        float a;
        float b;
    private:
};

#endif // TRECTANGLE_H
