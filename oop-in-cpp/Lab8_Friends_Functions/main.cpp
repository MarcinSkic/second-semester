#include <iostream>
#include <string>
#include "ThouseHolder.h"
#include "Tneighbour.h"

using namespace std;
string neighbourMethod(ThouseHolder &refer,int alarmCode);
int main()
{
    ThouseHolder father("Ojciec","sekretOjca",5223);
    ThouseHolder mother("Matka","SekretMatki",5223);
    ThouseHolder daughter("Corka","SekretCorki",5223);
    Tneighbour neighbour("Dobry sasiad");

    neighbour.show(&father);
    neighbour.show(&mother);
    neighbour.show(&daughter);

    cout<<"Sekret ojca: "<<neighbourMethod(father,543)<<endl;
    cout<<"Nowy kod: "<<ThouseHolder::getCode();


}
string neighbourMethod(ThouseHolder &refer,int alarmCode){
    refer.alarmCode = alarmCode;
    return refer.secret;
}
