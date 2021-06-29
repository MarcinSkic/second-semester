#include <iostream>
#include <locale>
#include <string>
#include "Tdate.h"
#include "Tperson2.h"

using namespace std;

int main()
{
    setlocale( LC_ALL,"" );
    {
        cout<<"Liczba obiektow: "<<Tperson2::getInstancesAmount()<<endl;

        Tperson2 defaultPerson;

        cout<<"Stworzona osoba: "<<endl;
        defaultPerson.show();

        cout<<endl;
        Tperson2 person("Jan","Kowalski",Tdate(20,9,2003));
        cout<<"Stworzona osoba: "<<endl;
        person.show();
        cout<<"Osoby te uczesczaja do: "<<Tperson2::getCollege()<<endl;
        cout<<endl;

        cout<<"Liczba obiektow: "<<Tperson2::getInstancesAmount()<<endl;

        cout<<"Roznica wieku wynosi: "<<person.calculateAgeDifference(defaultPerson)<<endl;


        cout<<"Osoba z dluzszym nazwiskiem to: "<<endl;
        person.getLongerSurname(defaultPerson).show();
    }


    return 0;
}
