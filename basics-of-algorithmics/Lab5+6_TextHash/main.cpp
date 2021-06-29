#include <iostream>
#include<sstream>
#include<fstream>
#include <string>
#include <math.h>
#include<cstdlib>

using namespace std;

string loadString(string info);
void naiveSolution(string text,string pattern);
void naiveTextComparison(string text,string pattern);
void KMPSolution(string text, string pattern);
void KRPSolution(string pattern, string text,int p,int offset);
int KRPMakeHash(char s,int offset,int p,int exp);
int KRPUpdateHash(int Hash,char s_previous,char s_next,int offset,int p,int exp);
void checkText(int p, int offset);

int main()
{
    int choice;
    string defaultText = "kotAlamakotaakotmaale";
    string defaultPattern = "kot";

    string text = defaultText;
    string pattern = defaultPattern;

    int p = 3;
    int offset = 65;


    while(true){
        cout<<endl<<"Co chcesz zrobic: "<<endl
        <<"1 - wczytac nowe dane tekstowe"<<endl
        <<"2 - Wyszukac algorytmem naiwnym"<<endl
        <<"3 - Wyszukac algorytmem KMP"<<endl
        <<"4 - Wyszukac algorytmem KRP"<<endl
        <<"5 - Wyjdz"<<endl
        <<endl<<"Aktualne dane: "<<endl
        <<"Tekst: "<<text<<endl
        <<"Wzorzec: "<<pattern<<endl
        <<endl<<"Twoj wybor: ";
        cin>>choice;

        fflush(stdin);

        switch(choice){
        case 1:
            text = loadString("Podaj tekst: ");
            pattern  = loadString("Podaj wzorzec: ");
            break;
        case 2:
            naiveSolution(text,pattern);
            break;
        case 3:
            KMPSolution(text,pattern);
            break;
        case 4:
            checkText(p,offset);
            break;
        case 5:
            return 0;
        default:
            cout<<"Zla opcja, powtorz"<<endl;
            break;
        }
    }

    return 0;

}
string loadString(string info){
    string text;
    cout<<info;
    //cin.ignore();
    getline(cin,text);
    return text;
}
/*int loadFile(student* &tab){
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
}*/
void checkText(int p, int offset){
    string text,pattern;
    ifstream file;
    file.open("tekst.txt");
    getline(file,pattern);
    cout<<pattern;
    while(!file.eof()){
        getline(file,text);
        cout<<"Kolejna linijka: "<<endl;
        KRPSolution(pattern,text,p,offset);
    }
    file.close();
}
void naiveSolution(string text,string pattern){
    int j = 0;
    bool foundAny = false;
    for (int i = 0; i < text.length();i++){
        if(text.at(i)==pattern.at(j)){
            if(j == pattern.length()-1){
                cout<<"Znaleziono wzorzec na indeksie: "<<i-pattern.length()+1<<endl;
                j = 0;
                foundAny = true;
            }
            j++;
        } else {
            j = 0;
            if(text.at(i)==pattern.at(j)){
                j++;
            }
        }

    }
    if(!foundAny){
        cout<<"Brak wzorcow w tym tekscie"<<endl;
    }
}
bool naiveTextComparison(string text,string pattern,int j){
    for(int i = 0; i < pattern.length();i++){
        if(pattern[i] == text[j]){
            j++;
        } else {
            return false;
        }
    }
    return true;
}
void KMPSolution(string text, string pattern){

}
void KMPdivision(){
}
void KMPsearch(string text, string pattern){

}
void KRPSolution(string pattern, string text,int p,int offset){
    int hashPattern = 0;
    int hashText = 0;
    int i = 0,j = 0;

    while(i<pattern.length()){
        hashPattern += KRPMakeHash(pattern.at(i),offset,p,pattern.length()-1-i);
        hashText += KRPMakeHash(text.at(i),offset,p,pattern.length()-1-i);

        i++;
    }

    i = pattern.length();
    while(i<=text.length()){

        if(hashPattern == hashText){
            if(naiveTextComparison(text,pattern,j)){
                cout<<"Znaleziono wzorzec na indeksie: "<<j<<endl;
            }

        }
        if(i<=text.length()){
            hashText=KRPUpdateHash(hashText,text[j],text[i],offset,p,pattern.length()-1);
            i++;
            j++;
        }
    }
}
int KRPMakeHash(char s,int offset,int p,int exp){
    int increase = ((int)s-offset)*(int)pow(p,exp);
    return increase;
}
int KRPUpdateHash(int Hash,char s_previous,char s_next,int offset,int p,int exp){
    Hash -= ((int)s_previous-offset)*(int)pow(p,exp);
    Hash *=p;
    Hash += ((int)s_next-offset);
    return Hash;
}
