#include <iostream>
#include<fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;
struct element{
    char character;
    element *next;
};
struct qqueue{
    element* head;
    element*tail;
};
void push(qqueue &q,char value){
    element *el = new element;
    el->character = value;
    el->next = nullptr;
    if(q.tail != nullptr){
        q.tail->next=el;
    } else {
        q.head = el;
    }
    q.tail = el;
}
void pop(qqueue &q){
    element *temp = q.head;
    q.head = q.head->next;
    delete temp;
    if(q.head==nullptr){
        q.tail = nullptr;
    }
}
bool isEmpty(qqueue q){
    if(q.head == nullptr){
        return true;
    } else {
        return false;
    }
}
char first(qqueue q){
    return q.head->character;
}
void firstChoice(qqueue q){
    if(isEmpty(q)){
        cout<<"Kolejka jest pusta"<<endl;
    } else {
        cout<<"Kolejka nie jest pusta"<<endl;
    }
}
void secondChoice(qqueue &q){
    char character =(char) (rand() % 25 + 65);
    push(q,character);
    cout<<"Do kolejki dodano znak: "<<character<<endl;
}
void thirdChoice(qqueue &q){
    if(isEmpty(q)){
        cout<<"Kolejka jest pusty"<<endl;
    }else{
        cout<<"Usunieto element: "<<first(q)<<endl;
        pop(q);
    }
}
void fourthChoice(qqueue &q){
    if(isEmpty(q)){
        cout<<"Kolejka jest pusta"<<endl;
    }else{
        cout<<"Element na przodzie kolejki: "<<first(q)<<endl;
    }
}
void fifthChoice(qqueue &q){
    if(isEmpty(q)){
        cout<<"Kolejka jest pusta, nie ma czego usuwac"<<endl;
        return;
    }
    cout<<"Rozpoczynam usuwanie elementow"<<endl;
    cout<<"Usunieto: ";
    while(!isEmpty(q)){
        cout<<first(q)<<", ";
        pop(q);
    }
    cout<<endl;
}
void sixthChoice(qqueue &q, string fileName){

    string load_file_name = fileName;
    ifstream loadFile;
    char c;
    loadFile.open(load_file_name.c_str());

    while(loadFile.get(c)){
        if((int)c >= 65 && (int)c <= 90){
            push(q,c);
        }
    }
    loadFile.close();
}
int main()
{
    qqueue q;
    q.head = nullptr;
    q.tail = nullptr;
    int choice;
    srand (time(NULL));
    while(true){
        cout<<"Co chcesz zrobic: "<<endl
        <<"\tSprawdzic czy kolejka jest pusty - 1"<<endl
        <<"\tDodac element do kolejki - 2"<<endl
        <<"\tUsunac element z kolejki - 3"<<endl
        <<"\tWyswietlic element z kolejki - 4"<<endl
        <<"\tWyczyscic kolejke - 5"<<endl
        <<"\tDodac znaki z tekstu - 6"<<endl
        <<"\tWyjsc - 7"<<endl;

        cout<<"Podaj swoj wybor: ";
        cin>>choice;

        switch (choice){
            case 1:
                firstChoice(q);
                break;
            case 2:
                secondChoice(q);
                break;
            case 3:
                thirdChoice(q);
                break;
            case 4:
                fourthChoice(q);
                break;
            case 5:
                fifthChoice(q);
                break;
            case 6:
                sixthChoice(q,"znaki2.txt");
                break;
            case 7:
                return 0;
            default:
                cout<<"Zly wybor, sprobuj jeszcze raz";
                break;
        }
    }
}
