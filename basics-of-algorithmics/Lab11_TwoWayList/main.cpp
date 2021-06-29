#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
struct element{
    element *next;
    element *prev;
    int value;
};
struct twoWayList{
    element *head;
    element *tail;
    int counter;
};
bool isEmpty(twoWayList l){
    if(l.head == nullptr){
        return true;
    }
    else {
        return false;
    }
}
void add_tail(twoWayList &l,int value){
    element* el=new element;
    el->value = value;
    el->next=nullptr;
    el->prev = nullptr;
    if(l.tail != nullptr){
        l.tail->next=el;
        el->prev=l.tail;
    } else{
        l.head = el;
    }
    l.tail = el;

    l.counter++;
}
void add_head(twoWayList &l,int value){
    element* el=new element;
    el->value = value;
    el->next = nullptr;
    el->prev = nullptr;

    if(l.head != nullptr){
        l.head->prev=el;
        el->next=l.head;
    } else {
        l.tail=el;
    }
    l.head = el;
    l.counter++;
}
void add_position(twoWayList &l,int value,int position){
    element *temp=l.head;
    for (int i = 1; i < position -1;i++){
        temp=temp->next;
    }
    element* el=new element;
    el->value = value;
    el->prev=temp;
    el->next=temp->next;
    temp->next->prev=el;
    temp->next=el;

    l.counter++;
}
void delete_tail(twoWayList &l){
    element* temp=l.tail;
    if(l.counter == 1){
        l.tail=nullptr;
        l.head=nullptr;
    } else {
        l.tail=l.tail->prev;
        l.tail->next=nullptr;
    }
    delete temp;
    l.counter--;
}
void delete_head(twoWayList &l){
    element* temp = l.head;
    if(l.counter == 1){
        l.tail=nullptr;
        l.head=nullptr;
    } else {
        l.head = l.head->next;
        l.head->prev=nullptr;
    }
    delete temp;
    l.counter--;
}
void delete_position(twoWayList &l,int position){
    element *temp=l.head;
    for (int i = 1; i < position-1;i++){
        temp=temp->next;
    }
    element *temp_del=temp->next;
    temp->next=temp_del->next;
    temp->next->prev=temp;
    delete temp_del;
    l.counter--;
}
int first(twoWayList l){
    return l.head->value;
}
int last(twoWayList l){
    return l.tail->value;
}
void showFromHead(twoWayList l){
    cout<<"Lista od poczatku: ";
    element *temp = l.head;
    for (int i = 1; i <= l.counter; i++){
        cout<<(temp->value)<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void showFromTail(twoWayList l){
    cout<<"Lista od konca: ";
    element *temp = l.tail;
    for(int i = 1; i <= l.counter; i++){
        cout<<(temp->value)<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}
void choice1(twoWayList l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
    } else {
        cout<<"Lista posiada "<<l.counter<<" elementow"<<endl;
    }
}
void choice2(twoWayList &l){
    int value = rand() % 50 + 1;
    add_tail(l,value);
    cout<<"Dodano: "<<value<<endl;
}
void choice3(twoWayList &l){
    int value = rand() % 50 + 1;
    add_head(l,value);
    cout<<"Dodano: "<<value<<endl;
}
void choice4(twoWayList &l){
    int value = rand() % 50 + 1;
    int position;
    cout<<"Podaj pozycje do jakiej chcesz dodac: "<<endl;
    cin>>position;
    if(position <= 1){
        cout<<"Podales indeks zmuszajacy do dodania do glowy"<<endl;
        add_head(l,value);
    } else if(position > l.counter){
        cout<<"Podales indeks zmuszajacy do dodania do ogona"<<endl;
        add_tail(l,value);
    }
    else {
        add_position(l,value,position);
    }
    cout<<"Dodano: "<<value<<endl;
}
void choice5(twoWayList &l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    cout<<"Usuwam z ogona: "<<last(l)<<endl;
    delete_tail(l);
}
void choice6(twoWayList &l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    cout<<"Usuwam z glowy: "<<first(l)<<endl;
    delete_head(l);
}
void choice7(twoWayList &l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    cout<<"Przed usuwaniem"<<endl;
    showFromHead(l);

    int position;
    cout<<"Podaj pozycje z jakiej chcesz usunac: "<<endl;
    cin>>position;

    if(position <= 1){
        cout<<"Podales indeks zmuszajacy do usuniecia z glowy"<<endl;
        delete_head(l);
    }
    else if(position >= l.counter){
        cout<<"Podales indeks zmuszajacy do usuniecia z ogona"<<endl;
        delete_tail(l);
    }
    else {
        delete_position(l,position);
    }

    cout<<"Po usunieciu"<<endl;
    showFromHead(l);
}
void choice8(twoWayList l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    showFromHead(l);
}
void choice9(twoWayList l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    showFromTail(l);
}
void choice10(twoWayList l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    element *temp = l.head;
    int minimum = temp->value,indexOfMin = 0;

    for (int i = 1; i <= l.counter; i++){
        if(minimum > temp->value){
            minimum = temp->value;
            indexOfMin = i;
        }
        temp=temp->next;
    }
    cout<<"Najmniejszy element znajduje sie na indeksie: "<<indexOfMin<<" i jest rowny "<<minimum<<endl;
}

void choice11(twoWayList &l){
    if(isEmpty(l)){
        cout<<"Lista juz jest pusta"<<endl;
        return;
    }
    while(l.counter > 0){
        delete_head(l);
    }
    cout<<"Usunieto!"<<endl;
}
void specialTask(twoWayList &l){

    int value;
    int amount = rand() % 15 + 5;

    for (int i = 0; i < amount;i++){
        value = rand() % 41 - 20;
        add_head(l,value);
    }

    int firstSize = l.counter;
    cout<<"Po wygenerowaniu: ";
    showFromHead(l);
    element *temp = l.head;

    for (int i = 1; i <= firstSize; i++){
        if(temp == l.tail || temp == l.head){
            cout<<"Ucieczka!";
        } else if (temp->next->value < 0 && temp->prev->value < 0){

            element *temp_del=temp;
            temp=temp->prev;

            temp->next=temp_del->next;
            temp->next->prev=temp;
            delete temp_del;
            l.counter--;
        }
        temp=temp->next;
    }

    cout<<"Po usuwaniu: ";
    showFromHead(l);
}

int main()
{
    srand (time(NULL));

    twoWayList l;
    l.head = nullptr;
    l.tail = nullptr;
    l.counter = 0;

    int choice;

    while(true){
        cout<<"Co chcesz zrobic: "<<endl
        <<"\tSprawdzic czy lista jest pusta - 1"<<endl
        <<"\tDodac element na koniec - 2"<<endl
        <<"\tDodac element na poczatek - 3"<<endl
        <<"\tDodac element na pozycje - 4"<<endl
        <<"\tUsunac element z konca - 5"<<endl
        <<"\tUsunac element z poczatku - 6"<<endl
        <<"\tUsunac element na pozycji - 7"<<endl
        <<"\tWyswietlic elementy od poczatku do konca - 8"<<endl
        <<"\tWyswietlic elementy od konca do poczatku - 9"<<endl
        <<"\tZnalezc element minimalny - 10"<<endl
        <<"\tUsunac cala liste - 11"<<endl
        <<"\tSpecjalneZadanie - 12"<<endl;

        fflush(stdin);
        cout<<"Podaj swoj wybor: ";
        cin>>choice;

        switch (choice){
            case 1:
                choice1(l);
                break;
            case 2:
                choice2(l);
                break;
            case 3:
                choice3(l);
                break;
            case 4:
                choice4(l);
                break;
            case 5:
                choice5(l);
                break;
            case 6:
                choice6(l);
                break;
            case 7:
                choice7(l);
                break;
            case 8:
                choice8(l);
                break;
            case 9:
                choice9(l);
                break;
            case 10:
                choice10(l);
                break;
            case 11:
                choice11(l);
                break;
            case 12:
                specialTask(l);
                return 0;
            default:
                cout<<"Zly wybor, sprobuj jeszcze raz";
                break;
        }
    }

    return 0;
}
