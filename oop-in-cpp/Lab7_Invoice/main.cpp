#include <iostream>
#include <string>
#include "Tclient.h"
#include "Tbill.h"
#include "Tdate.h"

using namespace std;

int main()
{
    cout<<"Bill 1:"<<endl;
    Tclient *client1 = new Tclient();
    client1->load();
    client1->show();

    Tbill bill1(client1);

    bill1.show();

    cout<<endl<<endl<<"Bill 2:"<<endl;
    Tclient *client2 = new Tclient("Konrad","Kowalski","3521342");

    Tbill bill2("Faktura 2",Tdate(),"555/65",3,client2);

    bill2.loadProducts();
    bill2.show();

    cout<<endl<<endl<<"Bill 3:"<<endl;
    Tbill *bill3 = new Tbill(client2);

    bill3->load();
    bill3->show();
    return 0;
}
