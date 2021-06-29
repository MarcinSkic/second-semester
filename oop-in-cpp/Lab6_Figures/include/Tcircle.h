#ifndef TCIRCLE_H
#define TCIRCLE_H
#include "Tfigure.h"
#include <string>

using namespace std;

class Tcircle : public Tfigure
{
    public:
        Tcircle();
        Tcircle(string name,float radius);
        virtual ~Tcircle();
        void draw();
        float calculateArea();
        float calculatePerimeter();

    protected:
        float radius;
    private:

};

#endif // TCIRCLE_H
