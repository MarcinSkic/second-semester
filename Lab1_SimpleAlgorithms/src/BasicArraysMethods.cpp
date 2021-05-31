#include "BasicArraysMethods.h"
#include <iostream>

using namespace std;

void BasicArraysMethods:: allocMemory1D(int *&tab, int n){
    tab = new int[n];
}
void BasicArraysMethods::  allocMemory2D(int **&tab,int w, int k){
    tab = new int*[w];
    for(int i = 0; i < w;i++){
        tab[i] = new int[k];
    }
}
void BasicArraysMethods:: fillArray1D(int *tab,int n, int a, int b){
    int liczba;
    for(int i = 0; i < n; i++){
        liczba = rand() % (b-a+1)+a;
        tab[i] = liczba;
    }
}
void BasicArraysMethods:: fillArray2D(int **tab,int w, int k, int a, int b){
    int liczba;
    for(int i = 0; i < w; i++){
        for(int x = 0; x < k; x++){
            liczba = rand() % (b-a+1)+a;
            tab[i][x] = liczba;
        }
    }
}
void BasicArraysMethods:: deleteArray1D(int *&tab){
    delete [] tab;
}
void BasicArraysMethods:: deleteArray2D(int **&tab,int w){
    for(int i = 0; i < w; i++){
        delete [] tab[i];
    }
    delete [] tab;
}
void BasicArraysMethods:: showArray1D(int* tab, int n){
    for(int i = 0; i< n; i++){
        cout<<setw(4)<<tab[i];
    }
    cout<<endl;
}
void BasicArraysMethods:: showArray2D(int** tab, int w, int k){
    for(int i = 0; i < w; i++){
        for(int x = 0; x < k; x++){
            cout<<setw(4)<<tab[i][x];
        }
        cout<<endl;
    }
}
