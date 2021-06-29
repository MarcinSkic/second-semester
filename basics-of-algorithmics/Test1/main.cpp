#include <iostream>
#include<fstream>
#include <math.h>
using namespace std;
void wczytaj(int *&tab, int &n, string nazwa_pliku) //n rozmiar tablicy, tab tablica
{
    ifstream odczyt;
    odczyt.open(nazwa_pliku.c_str());
    odczyt>>n;
    tab=new int[n];
    for(int i=0; i<n; i++)
    {
        odczyt>>tab[i];
    }
    odczyt.close();
}
void wczytaj1(string &wzorzec, string nazwa_pliku){ //wzorzec, nazwa pliku
    ifstream odczyt;
    odczyt.open(nazwa_pliku.c_str());
    odczyt>>wzorzec;
    odczyt.close();
}
void wczytaj2(string &wzorzec, string &tekst, string nazwa_pliku){ //wzorzec, tekst nazwa pliku
    ifstream odczyt;
    odczyt.open(nazwa_pliku.c_str());
    odczyt>>wzorzec;
    odczyt>>tekst;
    odczyt.close();
}
void bubbleSort(int * tab, int n,int startingIndex, int tryb){
    for(int i = startingIndex; i < n-1;i++){
        for (int x = startingIndex; x < n-1;x++){
            if(tryb < 0){
                if(tab[x]<tab[x+1]){
                    swap(tab[x],tab[x+1]);
                }
            } else {
                if(tab[x]>tab[x+1]){
                    swap(tab[x],tab[x+1]);
                }
            }
        }
    }
}
int KRPMakeHash(char s,int p,int exp){
    int increase = ((int)s)*(int)pow(p,exp);
    return increase;
}
float Exercise2(int* &tab,int n){
    bubbleSort(tab,n/2,0,-1);
    bubbleSort(tab,n,n/2,1);
    for(int i = 0; i < n; i++){
        cout<<tab[i]<<" ";
    }
    return (float)(tab[0]+tab[n/2])/2;
}
int Exercise3(string pattern,int p){
    int hashPattern;
    int i = 0;
    while(i<pattern.length()){
        hashPattern += KRPMakeHash(pattern.at(i),p,pattern.length()-1-i);
        i++;
    }
    return hashPattern;
}
int main()
{
    int* tabForEx2;
    int n, hashEx3;
    float result;
    string pattern;

    //Zad2
    cout<<"Zadanie 2: "<<endl;
    wczytaj(tabForEx2,n,"grupaDDzad2.csv");
    result = Exercise2(tabForEx2,n);
    cout<<endl<<"Srednia arytmetyczna: "<<result;

    //Zad3
    cout<<endl<<endl<<"Zadanie 3: ";
    wczytaj1(pattern,"grupaDDzad3.txt");
    hashEx3 = Exercise3(pattern,3);
    cout<<endl<<"Hash: "<<hashEx3;

    return 0;
}
