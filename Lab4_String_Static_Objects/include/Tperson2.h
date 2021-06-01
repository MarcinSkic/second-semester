#ifndef TPERSON2_H
#define TPERSON2_H
#include <string>
#include "Tdate.h"

using namespace std;


class Tperson2
{
    private:
        string name;
        string surname;
        string motto;
        Tdate birthdate;

        static string college;
        static int instancesAmount;

    public:
        Tperson2();
        Tperson2(const string &name,const string &surname,const Tdate &birthdate);
        void load();
        void show();
        string getFullname();
        int calculateAgeDifference(Tperson2 &person);
        Tperson2 getLongerSurname(Tperson2 &person);

        static int getInstancesAmount();
        static string getCollege();

        ~Tperson2();
};

#endif // TPERSON2_H
