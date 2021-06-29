#include "Tperson2.h"
#include "Tdate.h"
#include <iostream>
#include <string>

using namespace std;
int Tperson2::instancesAmount = 0;
string Tperson2::college = "Politechnika Lubelska";
Tperson2::Tperson2()
{
    name = "Marcin";
    surname = "Skic";
    birthdate = Tdate();
    motto = "Default motto";

    instancesAmount++;
    cout<<"Stworzono osobe: "<<this->getFullname()<<endl;
}
Tperson2::Tperson2(const string &name,const string &surname,const Tdate &birthdate){
    this->name = name;
    this->surname = surname;
    this->birthdate = birthdate;
    motto = "Motto Kowalskiego";
    instancesAmount++;
    cout<<"Stworzono osobe: "<<this->getFullname()<<endl;
}
void Tperson2::load(){
    cout<<"Podaj imie: ";
    cin>>name;
    cout<<"Podaj nazwisko: ";
    cin>>surname;

    birthdate.load();

    cout<<"Podaj motto: ";
    getline(cin,motto);
}
void Tperson2::show(){
    cout<<name<<" "<<surname<<" urodzony: ";
    birthdate.show();
    cout<<" z mottem: "<<motto<<endl;
}
string Tperson2::getFullname(){
    return name + " " + surname;
}
int Tperson2::calculateAgeDifference(Tperson2 &person){
    int ageDelta = birthdate.getYear() - person.birthdate.getYear();
    if(ageDelta < 0){
        ageDelta = -ageDelta;
    }
    return ageDelta;
}
Tperson2 Tperson2::getLongerSurname(Tperson2 &person){
    if(surname.length() < person.surname.length()){
        return person;
    } else {
        return *this;
    }
}
int Tperson2::getInstancesAmount(){
    return instancesAmount;
}
string Tperson2::getCollege(){
    return college;
}
Tperson2::~Tperson2()
{
    cout<<"Zniszczono osobe: "<<this->getFullname()<<endl;
    instancesAmount--;
}
