#include <iostream>

using namespace std;

template<class T>
struct asc
{
    bool operator()(T a, T b)
    {
        return a < b;
    }
};

template<class T>
struct desc
{
    bool operator()(T a, T b)
    {
        return a > b;
    }
};

template <class T, class O>
struct pivot
{
    int pivote;
    O comp;
    pivot(int m) : pivote(m) {}
    bool operator()(T a)
    {
        return comp(a, pivote);
    }
};

template<class U>
void pivotefunc(int* a, int* b, U pivotar)
{
    int* izquierda = a;
    
    for (int* actual = a; actual <= b; actual++)
    {
        if (pivotar(*actual))
        {
            int tmp = *actual;
            *actual = *izquierda;
            *izquierda = tmp;

            izquierda++;
        }
    }

    for (int* p = a; p <= b; p++)
    {
        cout << *p << " ";
    }
    cout << endl;
}

int main()
{
    int A[10] = { 3, 5, 4, 7, 6, 2, 1, 9, 0, 14 };
    cout << "el arreglo origin al es:" << endl;
    for (int*a = A; a <= A + 10 - 1; a++)
    {
        cout << *a << " ";
    }
    cout << endl;
    pivot<int,asc<int>> inst1(5);
    cout << "ascendente (con pivote 5):" << endl;
    pivotefunc(A, A + 10 - 1, inst1);
    int B[10] = { 3, 5, 4, 7, 6, 2, 1, 9, 0, 14 };
    cout << "descendente (con pivote 5):" << endl;
    pivot<int, desc<int>> inst2(5);
    pivotefunc(B, B + 10 - 1, inst2);
    return 0;
}
