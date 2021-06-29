#include "Trectangle.h"
#include <iostream>
#include <string>

Trectangle::Trectangle()
{
    cout<<"Constructor of Trectangle"<<endl;
    name = "Prostokat";
    a = 5;
    b = 7;
}
Trectangle::Trectangle(string name, float a,float b):Tfigure(name)
{
    cout<<"Constructor of Trectangle"<<endl;
    this->a = a;
    this->b = b;
}
void Trectangle::draw(){
    cout<<"Rysunek:"<<endl;
    cout<<"*******"<<endl
    <<"*     *"<<endl
    <<"*******"<<endl;
}
float Trectangle::calculateArea(){
    return a*b;
}
float Trectangle::calculatePerimeter(){
    return 2*a+2*b;
}

Trectangle::~Trectangle()
{
    cout<<"Destructor of Trectangle"<<endl;
}
