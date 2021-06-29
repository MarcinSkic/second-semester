#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;
void allocMemory1D(int *&tab, int n);
void allocMemory2D(int **&tab,int w, int k);
void fillArray1D(int *tab,int n, int a, int b);
void fillArray2D(int **tab,int w, int k, int a, int b);
void deleteArray1D(int *&tab);
void deleteArray2D(int **&tab,int w);
void showArray1D(int* tab, int n);
void showArray2D(int** tab, int w, int k);
void zadanie2();
void zadanie3();
void zadanie4();
void zadanie5();
int main()
{
    srand(time(NULL));
    int *tab;
    int length = 5;

    int **tab2;
    int rows = 5;
    int columns = 5;

    int lowerInterval = 2;
    int upperInterval = 20;

    int choice;
    while(true){
        cout<<"Co chcesz zrobic: "<<endl;
        cout<<"1 - zadanie2"<<endl;
        cout<<"2 - zadanie3"<<endl;
        cout<<"3 - zadanie4"<<endl;
        cout<<"4 - zadanie5"<<endl;
        cout<<"5 - wyjsc"<<endl;
        cout<<"Twoj wybor: ";
        cin>>choice;
        switch (choice){
            case 1:
                zadanie2();
                break;
            case 5:
                return 0;
            default:
                cout<<"Zly wybor"<<endl;
        }
    }




    //Testing
    cout<<"Tablica 1D:"<<endl;
    allocMemory1D(tab,length);
    fillArray1D(tab,length,lowerInterval,upperInterval);
    showArray1D(tab,length);
    deleteArray1D(tab);

    cout<<endl<<"Tablica 2D:"<<endl;

    allocMemory2D(tab2,rows,columns);
    fillArray2D(tab2,rows,columns,lowerInterval,upperInterval);
    showArray2D(tab2,rows,columns);
    deleteArray2D(tab2,rows);



}
void zadanie2(){
    int length,lowerInterval,upperInterval;
    int *arr;
    cout<<"Ten program znajdzie najmniejszy element w tablicy i powie czy jest to liczba pierwsza"<<endl;
    cout<<"Podaj wielkosc tablicy: ";
    cin>>length;
    cout<<"Podaj przedzial <a,b>: "<<endl;
    cin>>lowerInterval>>upperInterval;

    allocMemory1D(arr,length);
    fillArray1D(arr,length,lowerInterval,upperInterval);
    showArray1D(arr,length);


}
void allocMemory1D(int *&tab, int n){
    tab = new int[n];
}
void allocMemory2D(int **&tab,int w, int k){
    tab = new int*[w];
    for(int i = 0; i < w;i++){
        tab[i] = new int[k];
    }
}
void fillArray1D(int *tab,int n, int a, int b){
    int liczba;
    for(int i = 0; i < n; i++){
        liczba = rand() % (b-a+1)+a;
        tab[i] = liczba;
    }
}
void fillArray2D(int **tab,int w, int k, int a, int b){
    int liczba;
    for(int i = 0; i < w; i++){
        for(int x = 0; x < k; x++){
            liczba = rand() % (b-a+1)+a;
            tab[i][x] = liczba;
        }
    }
}
void deleteArray1D(int *&tab){
    delete [] tab;
}
void deleteArray2D(int **&tab,int w){
    for(int i = 0; i < w; i++){
        delete [] tab[i];
    }
    delete [] tab;
}
void showArray1D(int* tab, int n){
    for(int i = 0; i< n; i++){
        cout<<setw(4)<<tab[i];
    }
    cout<<endl;
}
void showArray2D(int** tab, int w, int k){
    for(int i = 0; i < w; i++){
        for(int x = 0; x < k; x++){
            cout<<setw(4)<<tab[i][x];
        }
        cout<<endl;
    }
}
