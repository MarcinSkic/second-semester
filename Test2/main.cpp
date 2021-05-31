#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;
//STOS
struct stackElement{
    int data;
    stackElement *next;
};
void push(stackElement* &stck,int value){
    stackElement *el = new stackElement;
    el->data = value;
    el->next = stck;
    stck = el;
}
void pop(stackElement* &stck){
    stackElement *temp=stck;
    stck=stck->next;
    delete temp;
}
bool isEmpty(stackElement* &stck){
    if(stck==nullptr){
        return true;
    } else {
        return false;
    }
}
int top(stackElement* stck){
    return stck->data;
}
//LISTA DWUKIERUNKOWA
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
void showFromHead(twoWayList l){
    cout<<"Lista od poczatku: ";
    element *temp = l.head;
    for (int i = 1; i <= l.counter; i++){
        cout<<(temp->value)<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void exercise1(){
    stackElement *stos = nullptr;
    int a, length = 0;

    ifstream myfile ("zad1j.txt");
    while ( myfile >> a)
    {
      push(stos,a);
      length++;
    }
    myfile.close();

    int shortestSequence = length;
    int currentSequence = 0;
    while(!isEmpty(stos)){
        if(top(stos) == 0){
            currentSequence++;
        } else if (currentSequence != 0){
            if(currentSequence < shortestSequence){
                shortestSequence = currentSequence;
                currentSequence = 0;
            }
        }
        pop(stos);
    }
    if(currentSequence != 0 && currentSequence < shortestSequence){ //Ostatnie sprawdzenie zabezpieczajace
        shortestSequence = currentSequence;
    }
    cout<<"Najkrotszy podciag rowna sie: "<<shortestSequence<<endl;
}
void exercise2(){
    twoWayList l;
    l.head = nullptr;
    l.tail = nullptr;
    l.counter = 0;

    int a;

    ifstream myfile ("zad2j.txt");
    while ( myfile >> a)
    {
      add_head(l,a);
    }
    myfile.close();

    element *temp = l.head;
    int firstSize = l.counter;

    for (int i = 1; i <= firstSize; i++){
        if((temp->value)<100 && (temp->value) >= 10){
            if(temp == l.head){
                delete_head(l);
                temp = l.head;
                continue;
            } else if (temp == l.tail){
                delete_tail(l);
                continue;
            }

            element *temp_del = temp;
            temp=temp->prev;

            temp->next=temp_del->next;
            temp->next->prev=temp;
            delete temp_del;

            l.counter--;

        }
        temp=temp->next;
    }
    showFromHead(l);

    while(l.counter > 0){
        delete_head(l);
    }
}
void exercise3(){
    twoWayList l;
    l.head = nullptr;
    l.tail = nullptr;
    l.counter = 0;

    int a;

    ifstream myfile ("zad2j.txt");
    while ( myfile >> a)
    {
      add_head(l,a);
    }
    myfile.close();

    element *temp = l.head;
    int firstSize = l.counter, value;

    for (int i = 1; i <= firstSize; i++){
        if((temp->value)<100 && (temp->value) >= 10){
            if(temp == l.head){
                delete_head(l);
                temp = l.head;
                continue;
            } else if (temp == l.tail){
                delete_tail(l);
                continue;
            }

            element *temp_del = temp;
            temp=temp->prev;

            temp->next=temp_del->next;
            temp->next->prev=temp;
            delete temp_del;

            l.counter--;

        }
        temp=temp->next;
    }

    srand(time(NULL));

    for (int i = 2; i <= l.counter; i+=3){
        value = rand() % 10 + 1;
        add_position(l,value,i);
    }
    showFromHead(l);

    while(l.counter > 0){
        delete_head(l);
    }
}
int main()
{
    cout<<"Zadanie1"<<endl<<"\t";
    exercise1();
    cout<<"Zadanie2"<<endl<<"\t";
    exercise2();
    cout<<"Zadanie3"<<endl<<"\t";
    exercise3();
}
