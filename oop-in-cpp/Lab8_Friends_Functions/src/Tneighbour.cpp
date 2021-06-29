#include "Tneighbour.h"
#include <string>
#include <iostream>

using namespace std;
Tneighbour::Tneighbour(string name)
{
    this->name = name;
}
void Tneighbour::show(ThouseHolder *pointer){
    cout<<"Ja sasiad "<<name
    <<" znam sekret domownika "<<pointer->name<<": "<<pointer->secret
    <<" i kod do ich domu: "<<pointer->alarmCode<<endl;
}
Tneighbour::~Tneighbour()
{
    //dtor
}
