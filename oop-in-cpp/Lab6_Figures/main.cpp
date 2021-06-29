#include <iostream>
#include "Tfigure.h"
#include "Tcircle.h"
#include "Trectangle.h"
#include "Tsquare.h"
#include <string>

using namespace std;

int main()
{
    Tfigure figure;
    figure.showEverything();
    cout<<endl<<endl;
    Tcircle circle;
    circle.showEverything();
    cout<<endl<<endl;
    Trectangle rectangle;
    rectangle.showEverything();
    cout<<endl<<endl;
    Tsquare *square = new Tsquare("Kwadracik",6);
    square->showEverything();
    delete square;
    return 0;

}
