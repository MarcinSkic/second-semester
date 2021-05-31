#include <iostream>
#include "ArrayMethods.h"
#include <time.h>

using namespace std;

void bubbleSort(int * tab, int n, int tryb);
void selectSort(int* tab, int n, int tryb);
void insertSort(int* tab, int n, int tryb);
void bubbleSort2D(int** tab, int w, int k, int tryb, int nrKol);
void zadanie2();
void zadanie3();
void zadanie4();
void zadanie5();

int main()
{
    srand(time(NULL));
    zadanie3();
    return 0;
}

void bubbleSort(int * tab, int n, int tryb){
    for(int i = 0; i < n-1;i++){
        for (int x = 0; x < n-i-1;x++){
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
void selectSort(int* tab, int n, int tryb){
    int ind;
    for(int i = 0; i < n;i++){
        ind = i;
        for (int x = i; x < n;x++){
            if(tab[ind]>tab[x]){
                ind = x;
            }
        }
        swap(tab[ind],tab[i]);
    }
}
void insertSort(int* tab, int n, int tryb){
    for(int i = 0; i < n;i++){
        for(int x = 0 ; x < n;x++){

        }
    }
}
void zadanie2(){
    int *tab,a = 1,b = 50,n = 20,tryb = 1,domyslny;
    ArrayMethods arrayMethods;

    cout<<"Czy chcesz zaladowac domyslne? (0 - tak, cokolwiek innego - nie): ";
    cin>>domyslny;

    if(domyslny != 0){
        cout<<"Podaj przedzial a/b: ";
        cin>>a>>b;
        cout<<"Podaj wielkosc tablicy: ";
        cin>>n;
        cout<<"Podaj tryb sortowania (malejaco to < 0, rosnaca to >= 0)";
        cin>>tryb;
    }

    arrayMethods.allocMemory1D(tab,n);
    arrayMethods.fillArray1D(tab,n,a,b);
    arrayMethods.showArray1D(tab,n);
    bubbleSort(tab,n,tryb);
    arrayMethods.showArray1D(tab,n);
    arrayMethods.deleteArray1D(tab);

}
void zadanie3(){
    int *tab,a = 1,b = 50,n = 20,tryb = -1,domyslny;
    ArrayMethods arrayMethods;

    cout<<"Czy chcesz zaladowac domyslne? (0 - tak, cokolwiek innego - nie): ";
    cin>>domyslny;

    if(domyslny != 0){
        cout<<"Podaj przedzial a/b: ";
        cin>>a>>b;
        cout<<"Podaj wielkosc tablicy: ";
        cin>>n;
        cout<<"Podaj tryb sortowania (malejaco to < 0, rosnaca to >= 0)";
        cin>>tryb;
    }

    arrayMethods.allocMemory1D(tab,n);
    arrayMethods.fillArray1D(tab,n,a,b);
    arrayMethods.showArray1D(tab,n);
    selectSort(tab,n,tryb);
    arrayMethods.showArray1D(tab,n);
    arrayMethods.deleteArray1D(tab);
}
void zadanie4(){

}
