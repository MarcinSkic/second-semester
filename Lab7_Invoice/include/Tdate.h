#ifndef TDATE_H
#define TDATE_H
#include <string>

using namespace std;

class Tdate
{
    public:
        Tdate(int day = 1,int month = 1,int year = 2000);
        virtual ~Tdate();
        void show();
        void load();
    protected:

    private:
        int day;
        int month;
        int year;
};

#endif // TDATE_H
