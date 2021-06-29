#include "Tbill.h"
#include "Tproduct.h"
#include "Tclient.h"
#include <string>
#include <iostream>
#include "Tdate.h"

using namespace std;

Tbill::Tbill(Tclient *client) : Tdocument()
{
    productsAmount = 5;
    this->client = client;
    this->products = new Tproduct[productsAmount]();
}
Tbill::Tbill(string name,Tdate signingDate,string number,int productsAmount, Tclient *client) : Tdocument(name,signingDate,number){
    this->client = client;
    this->productsAmount = productsAmount;
    this->products = new Tproduct[productsAmount]();
}
void Tbill::loadProducts(){
    for(int i = 0; i< productsAmount;i++){
        Tproduct product;
        product.load();
        products[i] = product;
    }
}
void Tbill::load(){
    Tdocument::load();

    cout<<endl<<"Podaj ile towarow: ";
    cin>>productsAmount;

    loadProducts();
}
void Tbill::show(){
    Tdocument::show();
    cout<<endl<<endl<<"Klienta: "<<endl;
    client->show();
    cout<<endl<<endl<<"Towary: "<<endl;
    for(int i = 0;i < productsAmount;i++){
        products[i].show();
        cout<<endl;
    }
    cout<<endl<<"Calkowity koszt: "<<calculateValue()<<endl;
}
float Tbill::calculateValue(){
    float result = 0;
    for(int i =0; i < productsAmount;i++){
        result += products[i].getCost();
    }
    return result;
}
Tbill::~Tbill()
{
    //dtor
}
