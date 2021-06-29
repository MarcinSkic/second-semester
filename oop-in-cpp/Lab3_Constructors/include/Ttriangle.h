#ifndef TTRIANGLE_H
#define TTRIANGLE_H


class Ttriangle
{
    private:
        int a,b,c;
    public:
        Ttriangle();
        Ttriangle(int a,int b,int c);
        float calculateArea();
        float calculateArea(int Ha);
        ~Ttriangle();
};

#endif // TTRIANGLE_H
