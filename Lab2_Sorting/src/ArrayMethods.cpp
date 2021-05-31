#include "ArrayMethods.h"
#include <iostream>
#include <iomanip>

using namespace std;

void ArrayMethods:: allocMemory1D(int *&tab, int n){
    tab = new int[n];
}
void ArrayMethods::  allocMemory2D(int **&tab,int w, int k){
    tab = new int*[w];
    for(int i = 0; i < w;i++){
        tab[i] = new int[k];
    }
}
void ArrayMethods:: fillArray1D(int *tab,int n, int a, int b){
    int liczba;
    for(int i = 0; i < n; i++){
        liczba = rand() % (b-a+1)+a;
        tab[i] = liczba;
    }
}
void ArrayMethods:: fillArray2D(int **tab,int w, int k, int a, int b){
    int liczba;
    for(int i = 0; i < w; i++){
        for(int x = 0; x < k; x++){
            liczba = rand() % (b-a+1)+a;
            tab[i][x] = liczba;
        }
    }
}
void ArrayMethods:: deleteArray1D(int *&tab){
    delete [] tab;
}
void ArrayMethods:: deleteArray2D(int **&tab,int w){
    for(int i = 0; i < w; i++){
        delete [] tab[i];
    }
    delete [] tab;
}
void ArrayMethods:: showArray1D(int* tab, int n){
    for(int i = 0; i< n; i++){
        cout<<setw(4)<<tab[i];
    }
    cout<<endl;
}
void ArrayMethods:: showArray2D(int** tab, int w, int k){
    for(int i = 0; i < w; i++){
        for(int x = 0; x < k; x++){
            cout<<setw(4)<<tab[i][x];
        }
        cout<<endl;
    }
}
