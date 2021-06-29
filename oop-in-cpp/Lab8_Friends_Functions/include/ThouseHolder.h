#ifndef THOUSEHOLDER_H
#define THOUSEHOLDER_H
#include <string>

using namespace std;

class ThouseHolder
{
    public:
        ThouseHolder(string name = "Marcin",string secret = "Ma swietnego kota",int alarmCode = 54235);
        virtual ~ThouseHolder();
        static void setCode(int newCode);
        static int getCode();
        void show();
        friend string neighbourMethod(ThouseHolder & refer,int alarmCode);
        friend class Tneighbour;
    private:
        string name;
        string secret;
        static int alarmCode;
};

#endif // THOUSEHOLDER_H
