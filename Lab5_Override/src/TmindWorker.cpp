#include "TmindWorker.h"
#include <iostream>
#include <string>

using namespace std;

TmindWorker::TmindWorker(string name, string surname, string company, float bonusPayment,float salary) : Tworker(name,surname,company,bonusPayment)
{
    cout<<"Init constructor for TmindWorker"<<endl;
    this->salary = salary;
}
void TmindWorker::show(){
    Tworker::show();
    cout<<"Placa miesieczna: "<<salary<<endl;
}
void TmindWorker::calculatePayment(){
    cout<<"Zarobek: "<<salary*(bonusPayment/100)+salary<<endl;
}
void TmindWorker::load(){
    Tworker::load();
    cout<<"Podaj place miesieczna: ";
    cin>>salary;
}
TmindWorker::~TmindWorker()
{
    cout<<"Init destructor for TmindWorker"<<endl;
}
