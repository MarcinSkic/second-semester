#include <iostream>
#include <string>

using namespace std;

template <typename T>
bool czy_palindrom(const T& t, int dlugosc){
    for(int i = 0; i < dlugosc/2;i++){
        if(t[i] != t[dlugosc-i-1]){
            return false;
        }
    }
    return true;
}

int main()
{
    char *tekst1 = "anilina";
    char tekst2[] = "Taki sobie napis";
    string tekst3("malajalam");
    int tab1[] = {1, 2, 3, 6, 3, 2, 1};
    int tab2[] = {1, 2, 3, 4, 4, 2, 1};
    char tab3[] = {'r', 'o', 't', 'a', 't', 'o', 'r'};
    cout<<"Czy tekst1 jest palindromem: "<<czy_palindrom<char*> (tekst1,7)<<endl;
    cout<<"Czy tekst2 jest palindromem: "<<czy_palindrom<char[17]> (tekst2,17)<<endl;
    cout<<"Czy tekst3 jest palindromem: "<<czy_palindrom<string> (tekst3,tekst3.length())<<endl;
    cout<<"Czy tab1 jest palindromem: "<<czy_palindrom<int[7]> (tab1,7)<<endl;
    cout<<"Czy tab2 jest palindromem: "<<czy_palindrom<int[7]> (tab2,7)<<endl;
    cout<<"Czy tab3 jest palindromem: "<<czy_palindrom<char [7]> (tab3,7)<<endl;
    return 0;
}
