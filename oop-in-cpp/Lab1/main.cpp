#include <iostream>
#include <cstdio>
#include <iomanip>
#include <math.h>

using namespace std;
namespace kolega1 {
    char imie[20] = "Kacper";
    int wiek = 22;
}
namespace kolega2{
    char imie[20] = "Marcin";
    int wiek = 19;
}
struct data{
    int rok;
    int miesiac;
    int dzien;
};
struct pracownik{
    char imie[20];
    char nazwisko[20];
    float stawkaZaGodzine;
    int liczbaGodzin;
    data dataZatrudnienia;
};
pracownik WczytajStruct ();
float ObliczPlace(pracownik p);
void Wyswietl(pracownik p);
int main()
{
    /*char imie[20] = "Tomasz";
    int wiek = 20;

    scanf("%s %d",imie,&wiek);
    printf("Wyswietlanie imienia: %s i wieku: %d\n",imie,wiek);

    cout<<setw(20)<<imie<<" "<<setw(4)<< wiek << endl;
    cout <<imie << " " << wiek  << endl;
    cout<<kolega1::imie<<" "<<kolega1::wiek<<endl;
    cout<<kolega2::imie<<" "<<kolega2::wiek<<endl;

    float r;
    cout<<"Podaj promien kola: ";
    cin>>r;

    float pole;
    pole = M_PI*pow(r,2);

    cout<<"Pole kola o promieniu "<<r<<" rowna sie "<<left<<setfill('-')<<setw(20)<<fixed<<setprecision(2)<<pole<<endl;*/
    pracownik p[3];
    for(int i = 0; i < 3;i++){
        p[i] = WczytajStruct();
    }
    for(int i = 0; i < 3;i++){
        Wyswietl(p[i]);
    }

    return 0;
}
pracownik WczytajStruct(){
    pracownik p;
    cout<<"Podaj imie: ";
    cin>>p.imie;
    cout<<"Podaj nazwisko: ";
    cin>>p.nazwisko;
    cout<<"Podaj stawke: ";
    cin>>p.stawkaZaGodzine;
    cout<<"Podaj liczbeGodzin: ";
    cin>>p.liczbaGodzin;
    cout<<"Podaj rok/miesiac/dzien: ";
    cin>>p.dataZatrudnienia.rok>>p.dataZatrudnienia.miesiac>>p.dataZatrudnienia.dzien;
    return p;
}
float ObliczPlace(pracownik p){
    return p.liczbaGodzin*p.stawkaZaGodzine;
}
void Wyswietl(pracownik p){
    cout<<setw(20)<<p.imie<<setw(20)<<p.nazwisko<<setw(5)<<p.dataZatrudnienia.rok<<setw(3)<<p.dataZatrudnienia.miesiac<<setw(3)<<p.dataZatrudnienia.dzien<<setw(10)<<ObliczPlace(p)<<endl;
}
