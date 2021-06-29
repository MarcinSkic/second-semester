#ifndef TTRUMPET_H
#define TTRUMPET_H
#include <string>
#include "Tinstrument.h"

using namespace std;

class Ttrumpet : public Tinstrument
{
    public:
        Ttrumpet();
        Ttrumpet(string name);
        virtual ~Ttrumpet();
        string getSound();

    protected:

    private:
};

#endif // TTRUMPET_H
