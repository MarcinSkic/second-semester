#include "Ttriangle.h"
#include <math.h>
#include <cmath>

Ttriangle::Ttriangle()
{
    a = 5;
    b = 3;
    c = 4;
}
Ttriangle::Ttriangle(int a,int b,int c){
    this->a = a;
    this->b = b;
    this->c = c;
}
float Ttriangle::calculateArea(){
    int p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
float Ttriangle::calculateArea(int Ha){
    return (a*Ha)/2;
}
Ttriangle::~Ttriangle()
{

}
