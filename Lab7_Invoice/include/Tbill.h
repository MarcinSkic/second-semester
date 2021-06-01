#ifndef TBILL_H
#define TBILL_H
#include "Tdocument.h"
#include "Tclient.h"
#include "Tproduct.h"
#include "Tdate.h"
#include <string>

using namespace std;

class Tbill : public Tdocument
{
    public:
        Tbill(Tclient *client);
        Tbill(string name,Tdate signingDate,string number, int productsAmount,Tclient *client);
        virtual ~Tbill();
        void loadProducts();
        void load();
        void show();
        float calculateValue();

    protected:
        int productsAmount;
        Tproduct * products;
        Tclient * client;
    private:

};

#endif // TBILL_H
