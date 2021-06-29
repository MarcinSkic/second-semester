#ifndef TDATE_H
#define TDATE_H


class Tdate
{
    private:
        int day;
        int month;
        int year;
    public:
        Tdate();
        Tdate(int day,int month,int year);
        void load();
        void show();
        int getYear();
        ~Tdate();
};

#endif // TDATE_H
