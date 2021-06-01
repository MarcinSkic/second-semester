#ifndef TMINDWORKER_H
#define TMINDWORKER_H
#include "Tworker.h"
#include <string>

using namespace std;

class TmindWorker : public Tworker
{
    public:
        TmindWorker(string name="Marcin",string surname = "Skic" ,string company = "Fedex",float bonusPayment = 15,float salary = 3000);
        virtual ~TmindWorker();
        void show();
        void load();
        void calculatePayment();

    protected:
        float salary;
    private:
};

#endif // TMINDWORKER_H
