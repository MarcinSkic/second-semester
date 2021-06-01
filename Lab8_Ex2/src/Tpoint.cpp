#include "Tpoint.h"

Tpoint::Tpoint(float x,float y)
{
    this->x = x;
    this->y = y;
}
void Tpoint::movePoint(float xDelta,float yDelta){
    x+=xDelta;
    y+=yDelta;
}
float Tpoint::getx(){
    return x;
}
float Tpoint::gety(){
    return y;
}
Tpoint::~Tpoint()
{
    //dtor
}
