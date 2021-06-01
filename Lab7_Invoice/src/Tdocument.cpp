#include "Tdocument.h"
#include <string>
#include <iostream>
#include "Tdate.h"

using namespace std;

Tdocument::Tdocument(string name,Tdate signingDate,string number)
{
    this->name = name;
    this->signingDate = signingDate;
    this->number = number;
}
void Tdocument::show(){
    cout<<name<<endl
    <<"Podpisana/y: ";
    signingDate.show();
    cout<<endl
    <<"O numerze: "<<number;
}
void Tdocument::load(){
    cout<<"Podaj nazwe dokumentu: ";
    cin>>name;
    signingDate.load();
    cout<<"Podaj numer dokumentu: ";
    cin>>number;
}
Tdocument::~Tdocument()
{
    //dtor
}
