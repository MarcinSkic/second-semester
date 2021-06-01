#ifndef TCLIENT_H
#define TCLIENT_H
#include <string>

using namespace std;

class Tclient
{
    public:
        Tclient(string name = "Marcin", string surname = "Skic", string NIP = "92432435");
        virtual ~Tclient();
        void load();
        void show();

    protected:
        string name;
        string surname;
        string NIP;
    private:
};

#endif // TCLIENT_H
