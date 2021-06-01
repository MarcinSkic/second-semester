#ifndef TNEIGHBOUR_H
#define TNEIGHBOUR_H
#include "ThouseHolder.h"


class Tneighbour
{
    public:
        Tneighbour(string name = "Woody");
        virtual ~Tneighbour();
        void show(ThouseHolder *pointer);

    protected:

    private:
        string name;
};

#endif // TNEIGHBOUR_H
