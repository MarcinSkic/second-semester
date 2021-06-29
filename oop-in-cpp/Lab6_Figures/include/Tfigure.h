#ifndef TFIGURE_H
#define TFIGURE_H
#include <string>
using namespace std;
class Tfigure
{
    public:
        Tfigure();
        Tfigure(string name);
        virtual ~Tfigure();
        void info();
        virtual void draw();
        virtual float calculateArea();
        virtual float calculatePerimeter();
        void showEverything();

    protected:
        string name;
    private:
};

#endif // TFIGURE_H
