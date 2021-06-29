#include "Tproduct.h"
#include <string>
#include <iostream>

using namespace std;

Tproduct::Tproduct(string name,float price,int amount)
{
    this->name = name;
    this->price = price;
    this->amount = amount;
}
void Tproduct::load(){
    cout<<"Podaj nazwe produktu: ";
    cin>>name;
    cout<<"Podaj cene: ";
    cin>>price;
    cout<<"Podaj ilosc: ";
    cin>>amount;
}
float Tproduct::getCost(){
    return price*amount;
}
void Tproduct::show(){
    cout<<"Produkt "<<name<<endl
    <<"O cenie "<<price<<endl
    <<"W ilosci "<<amount;
}
Tproduct::~Tproduct()
{
    //dtor
}
