#ifndef TCIRCLE_H
#define TCIRCLE_H
#include "Tpoint.h"

class Tcircle
{
    public:
        Tcircle(float r = 5);
        float getr();
        virtual ~Tcircle();

        friend bool belongs(Tpoint &point,Tcircle &circle);
    private:
        float r;
};

#endif // TCIRCLE_H
