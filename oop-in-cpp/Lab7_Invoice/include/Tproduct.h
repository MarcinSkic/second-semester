#ifndef TPRODUCT_H
#define TPRODUCT_H
#include <string>

using namespace std;

class Tproduct
{
    public:
        Tproduct(string name = "Jablko",float price = 2.5, int amount = 1);
        virtual ~Tproduct();
        void load();
        void show();
        float getCost();

    protected:
        string name;
        float price;
        int amount;
    private:
};

#endif // TPRODUCT_H
