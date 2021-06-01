#ifndef TINSTRUMENT_H
#define TINSTRUMENT_H
#include<string>

using namespace std;

class Tinstrument
{
    public:
        Tinstrument();
        Tinstrument(string name);
        virtual ~Tinstrument();
        virtual string getSound();
        void playMusic(int amountOfSounds);
    protected:
        string name;
    private:

};

#endif // TINSTRUMENT_H
