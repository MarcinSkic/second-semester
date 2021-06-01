#include "Tstudent.h"
#include <string>
#include <iostream>
#include "Tperson.h"

using namespace std;

Tstudent::Tstudent(string name, string surname, string college,int amountOfGrades) : Tperson(name,surname)
{
    cout<<"Init constructor for Tstudent"<<endl;
    this->grades = grades;
    this->college = college;
    this->amountOfGrades = amountOfGrades;

    grades = (int*)malloc(amountOfGrades*sizeof(int));
    for(int i = 0; i < amountOfGrades;i++){
        grades[i] = 2;
    }
}
void Tstudent::load(){
    Tperson::load();
    for(int i = 0; i < amountOfGrades; i++){
        cout<<"Podaj "<<i+1<<" ocene: ";
        cin>>grades[i];
    }
}
void Tstudent::didPassExamSession(){
    for(int i = 0; i < amountOfGrades;i++){
        if(grades[i]<=2){
            cout<<"Student nie zdal sesji"<<endl;
            return;
        }
    }
    cout<<"Student zdal sesje"<<endl;
}
void Tstudent::show(){

    Tperson::show();
    cout<<"Liczba ocen: "<<amountOfGrades<<", nazwa uczelni: "<<college<<endl;
    cout<<"Oceny: "<<endl;
    for(int i = 0; i < amountOfGrades;i++){
        cout<<"\t"<<grades[i]<<endl;
    }
}
Tstudent::~Tstudent()
{
    cout<<"Init destructor for Tstudent"<<endl;
    free(grades);
}
