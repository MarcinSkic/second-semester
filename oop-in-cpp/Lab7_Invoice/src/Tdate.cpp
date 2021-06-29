#include "Tdate.h"
#include <string>
#include <iostream>

using namespace std;

Tdate::Tdate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
void Tdate::show(){
    cout<<day<<"/"<<month<<"/"<<year;
}
void Tdate::load(){
    cout<<"Podaj date: (day/month/year)";
    cin>>day>>month>>year;
}
Tdate::~Tdate()
{
    //dtor
}
