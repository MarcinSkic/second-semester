#include "Ttrumpet.h"
#include "Tinstrument.h"
#include <string>
#include <iostream>

using namespace std;

Ttrumpet::Ttrumpet()
{
    cout<<"Constructor of Ttrumpet"<<endl;
    name = "Trumpet";
}
Ttrumpet::Ttrumpet(string name) : Tinstrument(name){
    cout<<"Constructor of Trumpet"<<endl;
}
string Ttrumpet::getSound(){
    return "tutu";
}

Ttrumpet::~Ttrumpet()
{
    cout<<"Destructor of Ttrumpet"<<endl;
    //dtor
}
