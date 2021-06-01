#include <iostream>
#include "Tperson.h"
#include "Tstudent.h"
#include "Tworker.h"
#include "ThandWorker.h"
#include "TmindWorker.h"

using namespace std;

int main()
{
    bool checkStudent = false;
    bool checkWorker = false;
    bool checkMindWorker = false;
    bool checkHandWorker = true;
    if(checkStudent){
        cout<<endl<<"Student: "<<endl;
        Tstudent student;

        student.show();
        student.didPassExamSession();
        student.load();
        student.show();
        student.didPassExamSession();
        cout<<endl;
        student.Tperson::show();
    }
    if(checkWorker){
        cout<<endl<<"Pracownik: "<<endl;
        Tworker worker;
        worker.show();
        worker.load();
        worker.show();
    }
    if(checkHandWorker){
        cout<<endl<<"Pracownik fizyczny: "<<endl;
        ThandWorker worker;
        worker.show();
        worker.calculatePayment();
        worker.load();
        worker.show();
    }
    if(checkMindWorker){
        cout<<endl<<"Pracownik umyslowy: "<<endl;
        TmindWorker worker;
        worker.show();
        worker.calculatePayment();
        worker.load();
        worker.show();
    }

}
