#include <iostream>
#include <locale>
#include "Tperson.h"
#include "Ttriangle.h"

using namespace std;

int main()
{
    int currentYear = 2021;
    int majorityAge = 18;
    setlocale( LC_ALL,"" );
    {
        cout<<"Osoba1:"<<endl;
        Tperson person1;

        person1.wyswietl();
        person1.info(currentYear,majorityAge);
        person1.info(currentYear);
    }
    {
        Tdate data;
        data.day = 5;
        data.month = 11;
        data.year = 2005;
        cout<<endl<<"Osoba2:"<<endl;
        Tperson person2("Jan","Kowalski",data);
        person2.wyswietl();
        person2.wyswietl(currentYear);
        person2.info(currentYear,majorityAge);
        person2.info(currentYear);
    }
    {
        Tdate data;
        data.day = 7;
        data.month = 3;
        data.year = 1986;
        cout<<endl<<"Osoba3 (wskaŸniki):"<<endl;
        Tperson *person3 = new Tperson("Basia","Nowak",data);
        person3->wyswietl(currentYear);
        person3->info(currentYear,majorityAge);
        delete person3;
    }
    {
        cout<<endl<<"Obliczenia na trójk¹cie:"<<endl;
        Ttriangle triangle(20,8,19);
        cout<<"Pole trójk¹ta z boków: "<<triangle.calculateArea()<<endl;
        cout<<"Pole trójk¹ta z wysokoœci i podstawy: "<<triangle.calculateArea(4)<<endl;
    }



    //person2.wczytaj();
    //person2.wyswietl();
    return 0;
}
