#include "ThouseHolder.h"
#include <iostream>
#include <string>
using namespace std;

int ThouseHolder::alarmCode=5;
ThouseHolder::ThouseHolder(string name, string secret,int alarmCode)
{
    this->name = name;
    this->secret = secret;
    this->alarmCode = alarmCode;
}
void ThouseHolder::setCode(int newCode){
    alarmCode = newCode;
}
int ThouseHolder::getCode(){
    return alarmCode;
}
void ThouseHolder::show(){
    cout<<"Nazwa: "<<name<<endl;
    cout<<"Sekret: "<<secret<<endl;
}
ThouseHolder::~ThouseHolder()
{

}
