#ifndef TVIOLIN_H
#define TVIOLIN_H
#include <string>
#include "Tinstrument.h"

using namespace std;

class Tviolin : public Tinstrument
{
    public:
        Tviolin();
        Tviolin(string name);
        virtual ~Tviolin();
        string getSound();

    protected:

    private:
};

#endif // TVIOLIN_H
