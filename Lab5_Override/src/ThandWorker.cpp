#include "ThandWorker.h"
#include <iostream>
#include <string>

using namespace std;

ThandWorker::ThandWorker(string name,string surname ,string company,float bonusPayment,float hourWage,int workedHours) : Tworker(name,surname,company,bonusPayment)
{
    cout<<"Init constructor for ThandWorker"<<endl;
    this->hourWage = hourWage;
    this->workedHours = workedHours;
}
void ThandWorker::show(){
    Tworker::show();
    cout<<"Placa za godzine: "<<hourWage<<endl;
    cout<<"Przepracowane godziny: "<<workedHours<<endl;
}
void ThandWorker::calculatePayment(){
    float temp = hourWage*workedHours;
    cout<<"Zarobek: "<<temp*(bonusPayment/100)+temp<<endl;
}
void ThandWorker::load(){
    Tworker::load();
    cout<<"Podaj zarobek za godzine: ";
    cin>>hourWage;
    cout<<"Podaj przepracowane godziny: ";
    cin>>workedHours;
}
ThandWorker::~ThandWorker()
{
    cout<<"Init destructor for ThandWorker"<<endl;
}
