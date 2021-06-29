#ifndef TDOCUMENT_H
#define TDOCUMENT_H
#include <string>
#include "Tdate.h"

using namespace std;


class Tdocument
{
    public:
        Tdocument(string name = "Dokumencik",Tdate signingDate = Tdate(),string number = "1111");
        virtual ~Tdocument();
        void load();
        void show();
    protected:
        string name;
        Tdate signingDate;
        string number;
    private:
};

#endif // TDOCUMENT_H
