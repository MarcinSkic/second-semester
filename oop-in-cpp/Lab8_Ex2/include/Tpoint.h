#ifndef TPOINT_H
#define TPOINT_H
#include "Tcircle.h"

class Tpoint
{
    public:
        Tpoint(float x = 2,float y = 3);
        void movePoint(float xDelta,float yDelta);
        float getx();
        float gety();
        virtual ~Tpoint();

        friend bool belongs(Tpoint &point,Tcircle &circle);
    private:
        float x;
        float y;
};

#endif // TPOINT_H
