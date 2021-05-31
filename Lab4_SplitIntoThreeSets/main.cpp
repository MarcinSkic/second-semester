#include <iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<cmath>

using namespace std;

struct student
{
    string imie;
    string nazwisko;
    int punkty;
};
int loadFile(student* &tab){
    string linia,pomoc;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;

    plik.open("studenci.csv");
    plik >> liczbaStudentow;

    tab=new student[liczbaStudentow];

    for(int i = 0; i < 2; i++)
        plik >> sredniki;

    for(int i=0; i<liczbaStudentow; i++)
    {
        plik>>linia;
        istringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);
        tab[i].punkty=atoi(pomoc.c_str());
    }
    plik.close();
    return liczbaStudentow;
}
void showStudents(student* tab, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Imie: "<<tab[i].imie<<"  Nazwisko: "<<tab[i].nazwisko<<"  Punkty: "<<tab[i].punkty<<endl;
    }
}
void showStudents(student* tab, int n, int middle){
    cout<<"Studenci ktorzy uzyskali <= 10 punktow: "<<endl;
    for(int i = 0; i < middle; i++){
        cout<<"Imie: "<<tab[i].imie<<"  Nazwisko: "<<tab[i].nazwisko<<"  Punkty: "<<tab[i].punkty<<endl;
    }
    cout<<"Studenci ktorzy uzyskali > 10 punktow: "<<endl;
    for(int i = middle; i < n; i++){
        cout<<"Imie: "<<tab[i].imie<<"  Nazwisko: "<<tab[i].nazwisko<<"  Punkty: "<<tab[i].punkty<<endl;
    }
}
void showStudents(student* tab,int n, int secondIndex,int thirdIndex){
    cout<<"Punkty podzielne przez 3: "<<endl;
    for(int i = 0; i <= secondIndex; i++){
        cout<<"Imie: "<<tab[i].imie<<"  Nazwisko: "<<tab[i].nazwisko<<"  Punkty: "<<tab[i].punkty<<endl;
    }
    cout<<"Punkty podzielne przez 3 z reszta 1: "<<endl;
    for(int i = secondIndex+1; i < thirdIndex; i++){
        cout<<"Imie: "<<tab[i].imie<<"  Nazwisko: "<<tab[i].nazwisko<<"  Punkty: "<<tab[i].punkty<<endl;
    }
    cout<<"Punkty podzielne przez 3 z reszta 2: "<<endl;
    for(int i = thirdIndex; i < n; i++){
        cout<<"Imie: "<<tab[i].imie<<"  Nazwisko: "<<tab[i].nazwisko<<"  Punkty: "<<tab[i].punkty<<endl;
    }
}
void deleteStudents(student* &tab){
    delete [] tab;
}
bool czyPierwsza(int num)
{
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    if(num!=0 && num!=1)
    {
        return true;
    }
    return false;
}
int flagaPolska(student* &tab,int n){
    int left = 0,right = n-1;
    while(left<right){
        while(left<right && tab[left].punkty<=10){
            left++;
        }
        while(left<right && tab[right].punkty>10){
            right--;
        }
        if(left < right){
            swap(tab[left],tab[right]);
            left++;
            right--;
        }
    }
    if(tab[left].punkty<=10){
        return left+1;
    } else {
        return left;
    }

}
int flagaFrancuska(student* &tab,int n,int &secondIndex,int &thirdIndex){
    int j =0;
    secondIndex = -1;
    thirdIndex = n;
    while(j<thirdIndex){
        if(tab[j].punkty%3==0){
            secondIndex++;
            swap(tab[secondIndex],tab[j]);
            j++;
        } else {
            if(tab[j].punkty%3==2){
                thirdIndex--;
                swap(tab[thirdIndex],tab[j]);
            } else {
                j++;
            }
        }
    }
}
int flagaFrancuskaPodLiczby(int* &tab,int n,int &secondIndex,int &thirdIndex){
    int j =0;
    secondIndex = -1;
    thirdIndex = n;
    while(j<thirdIndex){
        if(czyPierwsza(tab[j])){
            secondIndex++;
            swap(tab[secondIndex],tab[j]);
            j++;
        } else {
            if(tab[j]!=0 && tab[j]!=1){
                thirdIndex--;
                swap(tab[thirdIndex],tab[j]);
            } else {
                j++;
            }
        }
    }
}
void divideIntoTwo(student* &tab,int n){
    cout<<"Zadanie 4.2: "<<endl;
    cout<<"Przed podzialem: "<<endl;
    showStudents(tab,n);
    int middle = flagaPolska(tab,n);
    cout<<endl<<"Po podziale: "<<endl;
    showStudents(tab,n,middle);
}
void divideIntoThree(student* &tab,int n){
    int secondIndex,thirdIndex;
    cout<<"Przed podzialem: "<<endl;
    showStudents(tab,n);
    flagaFrancuska(tab,n,secondIndex,thirdIndex);
    cout<<endl<<"Po podziale: "<<endl;
    showStudents(tab,n,secondIndex,thirdIndex);
}
int main()
{
    int n = 15,secondIndex,thirdIndex;
    int* tab = new int[n];
    tab[0] = 5;
    tab[1] = 3;
    tab[7] = 43;
    tab[2] = 53;
    tab[3] = 89;
    tab[4] = 2;
    tab[5] = 7;
    tab[6] = 3;
    tab[8] = 34;
    tab[9] = 0;
    tab[10] = 32;
    tab[11] = 1;
    tab[12] = 11;
    tab[13] = 21;
    tab[14] = 99;


    flagaFrancuskaPodLiczby(tab,n,secondIndex,thirdIndex);
    for(int i =0; i < n; i++){
        cout<<tab[i]<<" ";
    }

    return 0;
}
