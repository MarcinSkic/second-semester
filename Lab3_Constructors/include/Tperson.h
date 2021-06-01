#ifndef TPERSON_H
#define TPERSON_H
#include <string>

using namespace std;

struct Tdate{
    int day;
    int month;
    int year;
};
class Tperson
{
    private:
        char imie[20];
        string nazwisko;
        Tdate dataUrodzenia;
    public:
        Tperson();
        Tperson(const char *imie,string nazwisko,Tdate dataUrodzenia);
        ~Tperson();
        void wczytaj();
        void wyswietl();
        void wyswietl(int currentYear);
        void info(int currentYear,int majorityAge);
        void info(int currentYear);
};

#endif // TPERSON_H
