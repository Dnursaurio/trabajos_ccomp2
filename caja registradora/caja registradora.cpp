#include <iostream>
using namespace std;

float plata(float monto)
{
    int monto200 = monto / 200;
    int monto100 = monto200 / 100;
    int monto50 = monto100 / 50;
    int monto20 = monto50 / 20;
    int monto10 = monto20 / 10;
    int monto5 = monto10 / 5;
    int monto2 = monto5 / 2;
    int monto1 = monto2 / 1;
    int monto50c = monto1 = 0.5;
    int monto20c = monto50c / 0.2;
    int monto10c = monto20c / 0.1;
    return monto;
}

int main()
{
    float x = 0;
    cout << "ingrese un monto, en caso de ser decimar usar el (.):"<< endl;
    cin >> x;
    cout << "el valor de x es: "<< x;
}