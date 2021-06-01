#ifndef TPERSON_H
#define TPERSON_H
#include <string>
using namespace std;
class Tperson
{
    public:
        Tperson(string name = "Marcin",string surname = "Skic");
        virtual ~Tperson();
        void show();
        void load();
    protected:
        string name, surname;
    private:
};

#endif // TPERSON_H
