#ifndef THANDWORKER_H
#define THANDWORKER_H
#include <string>
#include "Tworker.h"

using namespace std;


class ThandWorker : public Tworker
{
    public:
        ThandWorker(string name="Marcin",string surname = "Skic" ,string company = "Fedex",float bonusPayment = 30,float hourWage = 12,int workedHours = 40);
        virtual ~ThandWorker();
        void show();
        void load();
        void calculatePayment();
    protected:
        float hourWage;
        int workedHours;
    private:
};

#endif // THANDWORKER_H
