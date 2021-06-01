#include "Tclient.h"
#include <string>
#include <iostream>

using namespace std;

Tclient::Tclient(string name, string surname,string NIP)
{
    this->name = name;
    this->surname = surname;
    this->NIP = NIP;
}
void Tclient::load(){
    cout<<"Podaj imie: ";
    cin>>name;
    cout<<"Podaj nazwisko: ";
    cin>>surname;
    cout<<"Podaj NIP: ";
    cin>>NIP;
}
void Tclient::show(){
    cout<<"Klient "<<name<<" "<<surname<<endl
    <<"Z NIP = "<<NIP<<endl;
}
Tclient::~Tclient()
{

}
