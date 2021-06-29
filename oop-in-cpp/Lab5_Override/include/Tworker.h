#ifndef TWORKER_H
#define TWORKER_H
#include "Tperson.h"


class Tworker : public Tperson
{
    public:
        Tworker(string name = "Marcin", string surname="Skic", string company="Fedex", float bonusPayment=20);
        ~Tworker();
        void show();
        void load();
        void calculatePayment();

    protected:
        string company;

        float bonusPayment;

    private:
};

#endif // TWORKER_H
