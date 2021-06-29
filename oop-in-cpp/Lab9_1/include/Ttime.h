#ifndef TTIME_H
#define TTIME_H
#include <iostream>

using namespace std;

class Ttime
{
    public:
        Ttime(int minutes = 10,int hours = 2);
        virtual ~Ttime();
        int getMinutes();
        int getHours();
        Ttime operator+(Ttime b);
        Ttime operator-(Ttime b);
        Ttime operator*(int number);

        friend ostream & operator<<(ostream & os, const Ttime & t);

    protected:

    private:
        int minutes;
        int hours;

};

#endif // TTIME_H
