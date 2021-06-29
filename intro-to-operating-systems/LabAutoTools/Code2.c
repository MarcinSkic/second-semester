#include <stdio.h>
#include "libarea.h"
#include "libvolume.h"
int main(){
    int a = 4, b = 3, h = 5;
    printf("Pole prostokatu: %d\n",rectangleArea(a,b));
    printf("Pole prostopadloscianu %d\n",cuboidArea(a,b,h));
    printf("Objetosc prostopadloscianu %d\n",cuboidVolume(a,b,h));
}