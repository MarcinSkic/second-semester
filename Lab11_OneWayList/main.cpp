#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
struct element{
    element *next;
    int value;
};
struct oneWayList{
    element *head;
    element *tail;
    int counter;
};
bool isEmpty(oneWayList l){
    if(l.head == nullptr){
        return true;
    }
    else {
        return false;
    }
}
void add_tail(oneWayList &l,int value){
    element* el=new element;
    el->value = value;
    el->next=nullptr;
    if(l.tail != nullptr){
        l.tail->next=el;
    } else{
        l.head = el;
    }
    l.tail = el;

    l.counter++;
}
void add_head(oneWayList &l,int value){
    element* el=new element;
    el->value = value;
    el->next = l.head;
    l.head = el;
    if(l.tail == nullptr){
        l.tail = el;
    }

    l.counter++;
}
void add_position(oneWayList &l,int value,int position){
    element* el=new element;
    el->value = value;
    element *temp=l.head;
    for (int i = 1; i < position -1;i++){
        temp=temp->next;
    }
    el->next=temp->next;
    temp->next=el;

    l.counter++;
}
void delete_tail(oneWayList &l){
    element* temp=l.tail;
    if(l.counter == 1){
        l.tail=nullptr;
        l.head=nullptr;
    } else {
        element *bef_temp = l.head;
        for (int i = 1; i < l.counter-1;i++){
            bef_temp=bef_temp->next;
        }
        l.tail=bef_temp;
        l.tail->next=nullptr;
    }
    delete temp;
    l.counter--;
}
void delete_head(oneWayList &l){
    element* temp = l.head;
    l.head=l.head->next;
    if(l.counter == 1){
        l.tail=nullptr;
    }
    delete temp;
    l.counter--;
}
void delete_position(oneWayList &l,int position){
    element *prev=l.head;
    for (int i = 1; i < position-1;i++){
        prev=prev->next;
    }
    element *temp = prev->next;
    prev->next=temp->next;
    delete temp;
    l.counter--;
}
int first(oneWayList l){
    return l.head->value;
}
int last(oneWayList l){
    return l.tail->value;
}
void show(oneWayList l){
    cout<<"Lista: ";
    element *temp = l.head;
    for (int i = 1; i <= l.counter; i++){
        cout<<(temp->value)<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void showEvenIndexes(oneWayList l){
    cout<<"Lista parzystych indeksow: ";
    element *temp = l.head->next;
    for (int i = 2; i <= l.counter-1; i+=2){
        cout<<(temp->value)<<" ";
        temp=temp->next->next;
        if(temp == nullptr){
            return;
        }
    }
    cout<<endl;
}
void showAndAddNumbers(oneWayList &l){
    for (int i = 1; i <= l.counter; i++){
        cout<<(temp->value)<<" ";
        temp=temp->next;
    }
}
void choice1(oneWayList l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
    } else {
        cout<<"Lista posiada "<<l.counter<<" elementow"<<endl;
    }
}
void choice2(oneWayList &l){
    int value = rand() % 50 + 1;
    add_tail(l,value);
    cout<<"Dodano: "<<value<<endl;
}
void choice3(oneWayList &l){
    int value = rand() % 50 + 1;
    add_head(l,value);
    cout<<"Dodano: "<<value<<endl;
}
void choice4(oneWayList &l){
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
void choice5(oneWayList &l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    cout<<"Usuwam z ogona: "<<last(l)<<endl;
    delete_tail(l);
}
void choice6(oneWayList &l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    cout<<"Usuwam z glowy: "<<first(l)<<endl;
    delete_head(l);
}
void choice7(oneWayList &l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    cout<<"Przed usuwaniem"<<endl;
    show(l);

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
    show(l);
}
void choice8(oneWayList l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    cout<<"Pierwszy element: "<<first(l)<<endl;
}
void choice9(oneWayList l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    cout<<"Ostatni element: "<<last(l)<<endl;
}
void choice11(oneWayList l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    element *temp = l.head;
    float suma = 0,srednia;

    for (int i = 1; i <= l.counter; i++){
        suma += temp->value;
        temp=temp->next;
    }
    srednia = suma/l.counter;
    cout<<"Srednia wynosi: "<<srednia<<endl;
}
void choice12(oneWayList l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    element *temp = l.head;
    int maximum = -999999,indexOfMax = 0;

    for (int i = 1; i <= l.counter; i++){
        if(maximum < temp->value){
            maximum = temp->value;
            indexOfMax = i;
        }
        temp=temp->next;
    }
    cout<<"Najwiekszy element znajduje sie na indeksie: "<<indexOfMax<<" i jest rowny "<<maximum<<endl;
}
void choice13(oneWayList l){
    if(isEmpty(l)){
        cout<<"Lista jest pusta"<<endl;
        return;
    }
    show(l);
}
void choice14(oneWayList &l){
    if(isEmpty(l)){
        cout<<"Lista juz jest pusta"<<endl;
        return;
    }
    while(l.counter > 0){
        delete_head(l);
    }
    cout<<"Usunieto!"<<endl;
}

int main()
{
    srand (time(NULL));

    oneWayList l;
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
        <<"\tWyswietlic pierwszy element - 8"<<endl
        <<"\tWyswietlic ostatni element - 9"<<endl
        <<"\tPoliczyc srednia arytmetyczna - 11"<<endl
        <<"\tZnalezc element maksymalny - 12"<<endl
        <<"\tWyswietlic cala liste - 13"<<endl
        <<"\tUsunac cala liste - 14"<<endl
        <<"\tWyjsc - 15"<<endl;

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
            case 11:
                choice11(l);
                break;
            case 12:
                choice12(l);
                break;
            case 13:
                choice13(l);
                break;
            case 14:



                break;
            case 15:
                return 0;
            default:
                cout<<"Zly wybor, sprobuj jeszcze raz";
                break;
        }
    }

    return 0;
}
