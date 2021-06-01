#include "Tperson.h"
#include <string>
#include <iostream>

using namespace std;

Tperson::Tperson(string name, string surname){
    cout<<"Init constructor for Tperson"<<endl;
    this->name = name;
    this->surname = surname;
}
void Tperson::show(){
    cout<<name<<" "<<surname<<endl;
}
void Tperson::load(){
    cout<<"Podaj imie: ";
    cin>>name;
    cout<<"Podaj nazwisko: ";
    cin>>surname;
}
Tperson::~Tperson()
{
    cout<<"Init destructor for Tperson"<<endl;
}
