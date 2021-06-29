#include "Tcircle.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Tcircle::Tcircle()
{
    cout<<"Constructor of Tcircle"<<endl;
    name = "Kolko";
    radius = 5;
}
Tcircle::Tcircle(string name, float radius):Tfigure(name){
    cout<<"Constructor of Tcircle"<<endl;
    this->radius = radius;
}
void Tcircle::draw(){
    cout<<"Rysunek:"<<endl;
    cout<<"  *******"<<endl
    <<" *       *"<<endl
    <<"*         *"<<endl
    <<"*         *"<<endl
    <<"*         *"<<endl
    <<" *       *"<<endl
    <<"  *******"<<endl;
}
float Tcircle::calculateArea(){
    return radius*radius*M_PI;
}
float Tcircle::calculatePerimeter(){
    return radius*2*M_PI;
}
Tcircle::~Tcircle()
{
    cout<<"Destructor of Tcircle"<<endl;
}
