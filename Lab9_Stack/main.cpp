#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

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
void firstChoice(stackElement* &stck){
    if(isEmpty(stck)){
        cout<<"Stos jest pusty"<<endl;
    } else {
        cout<<"Stos nie jest pusty"<<endl;
    }
}
void secondChoice(stackElement* &stck){
    int number = rand() % 10 + 1;
    push(stck,number);
    cout<<"Do stosu dodano liczbe: "<<number<<endl;
}
void thirdChoice(stackElement* &stck){
    if(isEmpty(stck)){
        cout<<"Stos jest pusty"<<endl;
    }else{
        cout<<"Usunieto element: "<<top(stck)<<endl;
        pop(stck);
    }
}
void fourthChoice(stackElement* &stck){
    if(isEmpty(stck)){
        cout<<"Stos jest pusty"<<endl;
    }else{
        cout<<"Element na gorze stosu: "<<top(stck)<<endl;
    }
}
void fifthChoice(stackElement* &stck){
    while(!isEmpty(stck)){
        pop(stck);
    }
}
int main()
{
    stackElement *stck = nullptr;
    int choice;
    srand (time(NULL));
    while(true){
        cout<<"Co chcesz zrobic: "<<endl
        <<"\tSprawdzic czy stos jest pusty - 1"<<endl
        <<"\tDodac element do stosu - 2"<<endl
        <<"\tUsunac element ze stosu - 3"<<endl
        <<"\tWyswietlic element ze stosu - 4"<<endl
        <<"\tWyczyscic stos - 5"<<endl
        <<"\tWyjsc - 6"<<endl;

        cout<<"Podaj swoj wybor: ";
        cin>>choice;

        switch (choice){
            case 1:
                firstChoice(stck);
                break;
            case 2:
                secondChoice(stck);
                break;
            case 3:
                thirdChoice(stck);
                break;
            case 4:
                fourthChoice(stck);
                break;
            case 5:
                fifthChoice(stck);
                break;
            case 6:
                return 0;
                break;
            default:
                cout<<"Zly wybor, sprobuj jeszcze raz";
                break;
        }
    }





    push(stck,5);
    push(stck,3);
    push(stck,7);
    cout<<top(stck);
    pop(stck);
    cout<<top(stck);
}
