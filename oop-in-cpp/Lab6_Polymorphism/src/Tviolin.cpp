#include "Tviolin.h"
#include "Tinstrument.h"
#include <string>
#include <iostream>

using namespace std;

Tviolin::Tviolin()
{
    cout<<"Constructor of Violin"<<endl;
    name = "Violin";
}
Tviolin::Tviolin(string name):Tinstrument(name)
{
    cout<<"Constructor of Violin"<<endl;
}
string Tviolin::getSound(){
    return "pili";
}
Tviolin::~Tviolin()
{
    //dtor
}
