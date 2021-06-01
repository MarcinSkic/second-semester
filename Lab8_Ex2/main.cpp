#include <iostream>
#include <math.h>
#include <cmath>
#include "Tcircle.h"
#include "Tpoint.h"

using namespace std;
bool belongs(Tpoint &point,Tcircle &circle);
bool belongsNotFriend(Tpoint &point,Tcircle &circle);
int main()
{
    Tcircle circle;
    Tpoint point(0,0);
    cout<<"Wynik funkcji zaprzyjaznionej: "<<belongs(point,circle)<<endl;
    cout<<"Wynik funkcji tradycyjnej: "<<belongsNotFriend(point,circle)<<endl;
    point.movePoint(5,0);
    cout<<"Wynik funkcji zaprzyjaznionej: "<<belongs(point,circle)<<endl;
    cout<<"Wynik funkcji tradycyjnej: "<<belongsNotFriend(point,circle)<<endl;
    point.movePoint(-2,4);
    cout<<"Wynik funkcji zaprzyjaznionej: "<<belongs(point,circle)<<endl;
    cout<<"Wynik funkcji tradycyjnej: "<<belongsNotFriend(point,circle)<<endl;
    return 0;
}
bool belongs(Tpoint &point,Tcircle &circle){
    int d = sqrt(pow(point.x-0, 2)+pow(point.y-0, 2));
    if(d <= circle.r){
        return true;
    } else {
       return false;
    }
}
bool belongsNotFriend(Tpoint &point,Tcircle &circle){
    float d = sqrt(pow(point.getx()-0, 2)+pow(point.gety()-0, 2));
    if(d <= circle.getr()){
        return true;
    } else {
        return false;
    }
}

