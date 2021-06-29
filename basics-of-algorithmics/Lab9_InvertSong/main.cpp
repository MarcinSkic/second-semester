#include <iostream>
#include<fstream>
#include <string>

using namespace std;

struct stackElement{
    char character;
    stackElement *next;
};
void push(stackElement* &stck,char value){
    stackElement *el = new stackElement;
    el->character = value;
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
char top(stackElement* stck){
    return stck->character;
}
int main()
{
    stackElement *song=nullptr;
    string finishedSong="";

    string load_file_name = "piosenka.txt";
    string save_file_name = "wynik.txt";
    ifstream loadFile;
    ofstream saveFile;
    char c;
    loadFile.open(load_file_name.c_str());

    while(loadFile.get(c)){
        push(song,c);
    }
    loadFile.close();

    saveFile.open(save_file_name.c_str());

    while(!isEmpty(song)){
        char temp = top(song);
        cout<<temp;
        saveFile << temp;
        pop(song);
    }
    saveFile.close();
}
