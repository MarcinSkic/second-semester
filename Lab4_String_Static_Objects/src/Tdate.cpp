#include "Tdate.h"
#include <iostream>

using namespace std;

Tdate::Tdate()
{
    day = 5;
    month = 6;
    year = 2001;
}
Tdate::Tdate(int day,int month,int year):day(day),month(month),year(year){};
void Tdate::load(){
    cout<<"Podaj dzien: ";
    cin>>day;
    cout<<"Podaj miesiac: ";
    cin>>month;
    cout<<"Podaj rok: ";
    cin>>year;
}
void Tdate::show(){
    cout<<day<<"/"<<month<<"/"<<year;
}
int Tdate::getYear(){
    return year;
}
Tdate::~Tdate()
{
    //dtor
}
