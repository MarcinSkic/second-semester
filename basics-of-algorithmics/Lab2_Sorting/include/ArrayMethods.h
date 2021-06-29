#ifndef ARRAYMETHODS_H
#define ARRAYMETHODS_H


class ArrayMethods
{
    public:
    void allocMemory1D(int *&tab, int n);
    void allocMemory2D(int **&tab,int w, int k);
    void fillArray1D(int *tab,int n, int a, int b);
    void fillArray2D(int **tab,int w, int k, int a, int b);
    void deleteArray1D(int *&tab);
    void deleteArray2D(int **&tab,int w);
    void showArray1D(int* tab, int n);
    void showArray2D(int** tab, int w, int k);
};

#endif // ARRAYMETHODS_H
