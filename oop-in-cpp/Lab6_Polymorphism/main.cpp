#include <iostream>
#include <string>
#include "Tinstrument.h"
#include "Ttrumpet.h"
#include "Tviolin.h"

using namespace std;

int main()
{
    Tinstrument instrument;
    instrument.playMusic(5);

    Ttrumpet trumpet;
    trumpet.playMusic(5);

    Tviolin *violin = new Tviolin;
    violin->playMusic(3);
    return 0;
}
