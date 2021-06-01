#include "Tsquare.h"
#include <iostream>
#include <string>

Tsquare::Tsquare()
{
    cout<<"Constructor of Tsquare"<<endl;
    name = "Kwadrat";
    a = 5;
}
Tsquare::Tsquare(string name, float a):Tfigure(name){
    this->a = a;
}
void Tsquare::draw(){
    cout<<"Rysunek:"<<endl;
    cout<<"****"<<endl
    <<"*  *"<<endl
    <<"****"<<endl;
}
float Tsquare::calculateArea(){
    return a*a;
}
float Tsquare::calculatePerimeter(){
    return 4*a;
}
Tsquare::~Tsquare()
{
    //dtor
}
