#ifndef TSTUDENT_H
#define TSTUDENT_H
#include <string>
#include "Tperson.h"

using namespace std;

class Tstudent : public Tperson
{
    public:
        Tstudent(string name = "Jan",string surname="Kowalski",string college = "Politechnika Lubelska", int amountOfGrades = 2);
        virtual ~Tstudent();
        void load();
        void show();
        void didPassExamSession();
    protected:

    private:
        string college;
        int amountOfGrades;
        int* grades;

};

#endif // TSTUDENT_H
