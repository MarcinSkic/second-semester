#include "Tfigure.h"
#include <iostream>
#include <string>

using namespace std;

Tfigure::Tfigure()
{
    cout<<"Constructor of Tfigure"<<endl;
    name = "Base";
}
Tfigure::Tfigure(string name){
    this->name = name;
}
void Tfigure::info(){
    cout<<"Nazwa figury: "<<name<<endl;
}
void Tfigure::draw(){
    cout<<"Rysuje figure: "<<name<<endl;
}
float Tfigure::calculateArea(){
    return 0;
}
float Tfigure::calculatePerimeter(){
    return 0;
}
void Tfigure::showEverything(){
    info();
    draw();
    cout<<"Pole wynosi: "<<calculateArea()<<endl;
    cout<<"Obwod wynosi: "<<calculatePerimeter()<<endl;
}
Tfigure::~Tfigure()
{
    cout<<"Destructor of Tfigure"<<endl;
}
