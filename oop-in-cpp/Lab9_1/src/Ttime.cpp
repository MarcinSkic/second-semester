#include "Ttime.h"
#include <iostream>
using namespace std;
Ttime::Ttime(int minutes,int hours)
{
    this->minutes = minutes;
    this->hours = hours;
}
Ttime Ttime::operator+(Ttime b){
    //int localMinutes, localHours;
    Ttime suma(0,0);
    suma.hours = this->hours + b.hours;
    suma.minutes = this->minutes + b.minutes;
    if(suma.minutes >= 60){
        suma.hours += suma.minutes/60;
        suma.minutes = suma.minutes%60;
    }
    return suma;
}
Ttime Ttime::operator-(Ttime b){
    Ttime roznica(0,0);
    roznica.hours = this->hours - b.hours;
    roznica.minutes = this->minutes - b.minutes;

    int totalMinutes = roznica.hours*60+roznica.minutes;

    roznica.hours = totalMinutes/60;
    roznica.minutes = totalMinutes%60;
    return roznica;
}
Ttime Ttime::operator*(int number){
    Ttime product(0,0);
    product.hours = this->hours * number;
    product.minutes = this->minutes * number;
    if(product.minutes >= 60){
        product.hours += product.minutes/60;
        product.minutes = product.minutes%60;
    }
    return product;
}
int Ttime::getMinutes(){
    return minutes;
}
int Ttime::getHours(){
    return hours;
}
Ttime::~Ttime()
{
    //dtor
}
