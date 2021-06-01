#include <iostream>
#include <iomanip>
#include "Ttime.h"

using namespace std;
ostream & operator<<(ostream & os, const Ttime & t);
Ttime operator*(int number, Ttime time);
bool operator==(Ttime a,Ttime b);
int main()
{
    Ttime lot1(5,6), lot2(10,1), oczekiwanie(20,0),lot3(30,1);
    cout<<"Czas trwania lotu Chicago-Paryz: "<<lot1<<endl;
    cout<<"Czas oczekiwania: "<<oczekiwanie<<endl;
    cout<<"Czas trwania lotu Paryz-Warszawa: "<<lot2<<endl;
    cout<<"Calkowity czas podrozy: "<<(lot1+lot2+oczekiwanie)<<endl;

    lot3 = lot3*2;
    lot2 = 2*lot2;

    if(lot3==lot2){
        cout<<"Czasy lotu sa takie same"<<endl;
    } else {
        cout<<"Czasy lotu sa rozne"<<endl;
    }
    /*{
        Ttime time;
        Ttime wynik;
        Ttime timeTwo(60,0);
        wynik = time+timeTwo;
        cout<<"Suma: "<<wynik.getHours()<<":"<<wynik.getMinutes()<<endl;
        wynik = time-timeTwo;
        cout<<"Roznica: "<<wynik<<endl;
        wynik = 3*time;
        cout<<"Mnozenie: "<<wynik<<endl;
        cout<<"Porownanie "<<wynik<<" do "<<time<<" = "<<(wynik==time)<<endl;
        time = time*3;
        cout<<"Porownanie "<<wynik<<" do "<<time<<" = "<<(wynik==time)<<endl;
    }*/


    return 0;
}
ostream & operator<<(ostream & os, const Ttime & t){
    os<<t.hours<<":"<<setfill('0')<<setw(2)<<t.minutes;
    return os;
}

Ttime operator*(int number, Ttime time){
    int hours = time.getHours(), minutes = time.getMinutes();
    hours *= number;
    minutes *= number;
    if(minutes >= 60){
        hours += minutes/60;
        minutes = minutes%60;
    }
    return Ttime(minutes,hours);
}
bool operator==(Ttime a,Ttime b){
    if(a.getHours() == b.getHours() && a.getMinutes() == b.getMinutes()){
        return true;
    }
    return false;
}
