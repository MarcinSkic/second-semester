#include <iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
using namespace std;

struct student
{
    string imie;
    string nazwisko;
    int punkty;
};
void showStudent(student x){
    cout<<"Imie: "<<x.imie<<"  Nazwisko: "<<x.nazwisko<<"  Punkty: "<<x.punkty<<endl;
}
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
void quickSort(student* tab, int lewy, int prawy, int tryb)
{
    int srodek = (int)(lewy + prawy) / 2;
    student piwot = tab[srodek];

    tab[srodek] = tab[prawy];
    int granica = lewy;
    for (int i = lewy; i < prawy; i++)
    {
        if ((tab[i].punkty > piwot.punkty && tryb == 1))
        {
            std::swap(tab[granica], tab[i]);
            granica++;
        }
        else if (tab[i].punkty < piwot.punkty && tryb == 0)
        {
            std::swap(tab[granica], tab[i]);
            granica++;
        }
    }
    tab[prawy] = tab[granica];
    tab[granica] = piwot;
    if (lewy < granica - 1)
        quickSort(tab, lewy, granica - 1, tryb);
    if (granica + 1 < prawy)
        quickSort(tab, granica + 1, prawy, tryb);
}
void naiveSearch(student* tab, int n,int searchedPoints){
    bool found = false;
    for(int i = 0; i < n; i++){
        if(tab[i].punkty == searchedPoints){
            found = true;
            showStudent(tab[i]);
        }
    }
    if(!found){
        cout<<"Nie znaleziono studenta ktory by mial "<<searchedPoints<<" punktow"<<endl;
    }
}
int binarySearch(student* tab,student* &answers,int n,int searchedPoints){
    bool found = false;
    int left = 0, right = n-1,middle,index,foundStudents = 0;

    while(left <= right){
        middle = (int)(left+right)/2;
        if(tab[middle].punkty == searchedPoints){
            showStudent(tab[middle]);
            answers[foundStudents] = tab[middle];
            foundStudents++;
            break;
        } else {
            if(searchedPoints < tab[middle].punkty){
                right = middle-1;
            } else {
                left = middle+1;
            }
        }
    }
    index = middle-1;
    while(index >=0 && tab[index].punkty == searchedPoints){
        showStudent(tab[index]);
        answers[foundStudents] = tab[index];
        foundStudents++;
        index--;
    }
    index = middle+1;
    while(index <n && tab[index].punkty == searchedPoints){
        showStudent(tab[index]);
        answers[foundStudents] = tab[index];
        foundStudents++;
        index++;
    }
    if(foundStudents == 0){
        cout<<"Nie znaleziono studenta ktory by mial "<<searchedPoints<<" punktow"<<endl;
    }
    return foundStudents;
}
void showStudents(student* tab, int n)
{
    for(int i=0; i<n; i++)
    {
        showStudent(tab[i]);
    }
}
void deleteStudents(student* &tab){
    delete [] tab;
}
void saveFile(student* tab,int n,int searchedPoints){
    ofstream zapis;
    string sciezkaDoZapisu="wyniki.csv";
    zapis.open(sciezkaDoZapisu);

    zapis<<n<<";"<<"Szukane punkty:;"<<searchedPoints<<endl;
    for(int i=0; i<n; i++){
        zapis<<tab[i].imie<<";"<<tab[i].nazwisko<<";"<<endl;
    }

    zapis.close();
}
int main()
{
    int n,foundStudents, searchedPointsOne = 30,searchedPointsTwo = 30;
    student* tab;
    student* answer;
    n = loadFile(tab);
    answer = new student[n];
    quickSort(tab,0,n-1,0);
    showStudents(tab,n);

    cout<<endl<<"Studenci posiadajacy "<<searchedPointsOne<<" punktow: (szukanie naiwne)"<<endl;
    naiveSearch(tab,n,searchedPointsOne);

    cout<<endl<<"Studenci posiadajacy "<<searchedPointsTwo<<" punkty: (szukanie binarne)"<<endl;
    foundStudents = binarySearch(tab,answer,n,searchedPointsTwo);

    saveFile(answer,foundStudents,searchedPointsTwo);
    deleteStudents(tab);

    return 0;
}
