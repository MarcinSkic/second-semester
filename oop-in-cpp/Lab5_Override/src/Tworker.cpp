#include "Tworker.h"
#include <iostream>

using namespace std;

Tworker::Tworker(string name, string surname, string company, float bonusPayment) : Tperson(name,surname)
{
    cout<<"Init constructor for Tworker"<<endl;
    this->company = company;
    this->bonusPayment = bonusPayment;
}
void Tworker:: show(){
    Tperson::show();
    cout<<"Nazwa firmy: "<<company<<endl;
    cout<<"Premia: "<<bonusPayment<<endl;
}
void Tworker::load(){
    Tperson::load();
    cout<<"Podaj nazwe firmy: ";
    cin>>company;
    cout<<"Podaj premie : ";
    cin>>bonusPayment;
}
Tworker::~Tworker()
{
    cout<<"Init destructor for Tworker"<<endl;
}
