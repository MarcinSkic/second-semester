#include <iostream>

using namespace std;

template <class typ>
class tab
{
    public:
        void Wczytaj(typ arr[]);
        void Drukuj();
    private:
        typ t[10];
};

template <class typ>
void tab<typ>::Wczytaj(typ arr[]){
    for (int i = 0; i < 10; i++){
        t[i] = arr[i];
    }
}

template <class typ>
void tab<typ>::Drukuj(){
    cout<<"Tablica: ";
    for(int i = 0; i < 10; i++){
        cout<<t[i]<<" ";
    }
}
int main()
{
    int tab1[] = {1, 2, 3, 6, 3, 2, 1,8,43,10};
    float tab2[] = {5.5, 6.7, 4, 9.3, 5, 34, 54, 33.33, 9, 13};
    string tab3[] = {"Polska","Niemcy","Rosja","Francja","USA","Czechy","Litwa","Estonia","Japonia","Chiny"};
    tab<int> integers;
    tab<float> floats;
    tab<string> countries;
    cout<<"Liczby calkowite: "<<endl<<"\t";
    integers.Wczytaj(tab1);
    integers.Drukuj();
    cout<<endl<<"Liczby rzeczywiste: "<<endl<<"\t";
    floats.Wczytaj(tab2);
    floats.Drukuj();
    cout<<endl<<"Nazwy krajow: "<<endl<<"\t";
    countries.Wczytaj(tab3);
    countries.Drukuj();

    return 0;
}
