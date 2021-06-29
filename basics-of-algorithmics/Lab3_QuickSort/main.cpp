#include <iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
using namespace std;
struct punkt
{
    int x;
    int y;
};
struct student
{
    string imie;
    string nazwisko;
    int punkty;
};

void testMethod(){
        punkt p;
       p.x=1;
       p.y=2;
       cout<<"Punkt: "<<p.x<<"  "<<p.y<<endl;

       punkt *p1=new punkt;
       p1->x=3;
       p1->y=4;
       cout<<"Punkt: "<<p1->x<<"  "<<p1->y<<endl;

       delete p1;
       p1=nullptr;

       punkt tab2[3];
       for(int i=0; i<3; i++)
       {
           cout<<"Podaj punkt x: ";
           cin>>tab2[i].x;
            cout<<"Podaj punkt y: ";
           cin>>tab2[i].y;
       }
       for(int i=0; i<3; i++)
       {
           cout<<"Punkt: "<<tab2[i].x<<"  "<<tab2[i].y<<endl;
       }

       punkt* tab1=new punkt[3];
       tab1[0].x=100;
       tab1[0].y=200;
       tab1[1].x=300;
       tab1[1].y=400;
       cout<<"Punkt: "<<tab1[0].x<<"  "<<tab1[0].y<<endl;
       cout<<"Punkt: "<<tab1[1].x<<"  "<<tab1[1].y<<endl;

       delete [] tab1;

       punkt** tab3=new punkt*[2];
       for(int i=0;i<2;i++){
           tab3[i]=new punkt;
           tab3[i]->x=i*200;
           tab3[i]->y=i+200;
       }
       cout<<"Punkt: "<<tab3[0]->x<<"  "<<tab3[0]->y<<endl;
       cout<<"Punkt: "<<tab3[1]->x<<"  "<<tab3[1]->y<<endl;

       for(int i=0;i<2;i++){
           delete tab3[i];
       }
       delete [] tab3;
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
void showStudents(student* tab, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Imie: "<<tab[i].imie<<"  Nazwisko: "<<tab[i].nazwisko<<"  Punkty: "<<tab[i].punkty<<endl;
    }
}
void deleteStudents(student* &tab){
    delete [] tab;
}

void quickSort(student* &tab,int left,int right, int tryb){
    if(right <= left) return;
    int srodek = (left+right)/2;
    student piwot = tab[srodek];
    tab[srodek] = tab[right];
    int granica = left;

    for(int i = 0; i < right;i++){
        if(tab[i].punkty<piwot.punkty){
            swap(tab[granica], tab[i]);
            granica++;
        }
    }
    tab[right] = tab[granica];
    tab[granica] = piwot;
    if(left < granica-1){
        quickSort(tab,left,granica-1,tryb);
    }
    if(right> granica+1){
        quickSort(tab,granica+1,right,tryb);
    }
}
int main()
{
    int n;
    student* tab;
    n = loadFile(tab);
    cout<<"Przed sortowaniem: "<<endl;
    showStudents(tab,n);
    quickSort(tab,0,n-1,1);
    cout<<"Posortowane: "<<endl;
    showStudents(tab,n);

    deleteStudents(tab);

    return 0;
}
