#include "Tperson.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

Tperson::Tperson()
{
    Tdate data;
    data.day = 5;
    data.month = 10;
    data.year = 2001;
    strcpy(imie, "Marcin");
    nazwisko = "Skic";
    dataUrodzenia = data;
    cout<<"Dziala konstruktor domyslny"<<endl;
}
Tperson::Tperson(const char *imie,string nazwisko,Tdate dataUrodzenia)
{
    strncpy(this->imie,imie,19);
    this->imie[19]='\0';
    this->nazwisko = nazwisko;
    this->dataUrodzenia = dataUrodzenia;
    cout<<"Dziala konstruktor z argumentami"<<endl;
}
void Tperson::wczytaj(){
    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    cout<<"Podaj date (d/m/y): ";
    cin>>dataUrodzenia.day>>dataUrodzenia.month>>dataUrodzenia.year;
}
void Tperson::wyswietl(){
    cout<<"Imie: "<<imie<<endl;
    cout<<"Nazwisko: "<<nazwisko<<endl;
    cout<<"Data: "<<dataUrodzenia.day<<"/"<<dataUrodzenia.month<<"/"<<dataUrodzenia.year<<endl;
}
void Tperson::wyswietl(int currentYear){
    cout<<"Imie: "<<imie<<endl;
    cout<<"Nazwisko: "<<nazwisko<<endl;
    cout<<"Wiek: "<<currentYear - dataUrodzenia.year<<endl;
}
void Tperson::info(int currentYear){
    int age = currentYear - dataUrodzenia.year;
    int ageDelta = age - 18;
    if(ageDelta < 0){
        cout<<"Osoba ta nie ukoñczy³a 18 lat"<<endl;
    } else {
        cout<<"Osoba ta ukoñczy³a 18 w "<<currentYear-ageDelta<<endl;
    }
}
void Tperson::info(int currentYear,int majorityAge){
    int age = currentYear - dataUrodzenia.year;
    if(age < majorityAge){
        cout<<"Osoba ta jest dzieckiem"<<endl;
    } else if(age <= 30){
        cout<<"Osoba ta jest pe³noletnia"<<endl;
    } else if(age <= 50){
        cout<<"Osoba ta jest 30+"<<endl;
    } else {
        cout<<"Osoba ta jest 50+"<<endl;
    }
}
Tperson::~Tperson()
{
    cout<<"Destruktor dziala"<<endl;
}
