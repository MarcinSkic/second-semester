#include "Tinstrument.h"
#include <string>
#include <iostream>

using namespace std;

Tinstrument::Tinstrument()
{
    cout<<"Constructor of Tinstrument"<<endl;
    name = "Nieznany";
}
Tinstrument::Tinstrument(string name){
    cout<<"Constructor of Tinstrument"<<endl;
    this->name = name;
}
string Tinstrument::getSound(){
    return "baseSound";
}
void Tinstrument::playMusic(int amountOfSounds){
    for(int i = 0; i < amountOfSounds;i++){
        cout<<getSound()<<endl;
    }
}
Tinstrument::~Tinstrument()
{
    cout<<"Destructor of Tinstrument"<<endl;
}
