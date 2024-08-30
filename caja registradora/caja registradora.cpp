#include <iostream>
#include <iomanip>
using namespace std;
void plata(long double monto)
{
    
    //Deteccion de la parte entera en soles
    int montocompleto = static_cast<int>(monto);
    //deteccionde la parte decimal en centimos
    int centimos = static_cast<int>((monto - montocompleto) * 100);
    //controlamos los billetes y las monedas
    int monto200 = montocompleto / 200;
    montocompleto %= 200;
    int monto100 = montocompleto / 100;
    montocompleto %= 100;
    int monto50 = montocompleto / 50;
    montocompleto %= 50;
    int monto20 = montocompleto / 20;
    montocompleto %= 20;
    int monto10 = montocompleto / 10;
    montocompleto %= 10;
    int monto5 = montocompleto / 5;
    montocompleto %= 5;
    int monto2 = montocompleto / 2;
    montocompleto %= 2;
    int monto1 = montocompleto/ 1;
    montocompleto %= 1;
    //controlamos la logica de loos centimos
    int centimos50 = centimos / 50;
    centimos %= 50;
    int centimos20 = centimos / 20;
    centimos %= 20;
    int centimos10 = centimos / 10;
    centimos %= 10;
    int *sobra = &centimos;
    //Impresion en Enteros
    cout << "la cantidad de billetes de S/.200 devueltos son: " << monto200 << endl;
    cout << "la cantidad de billetes de S/.100 devueltos son: " << monto100 << endl;
    cout << "la cantidad de billetes de S/.50 devueltos son: " << monto50 << endl;
    cout << "la cantidad de billetes de S/.20 devueltos son: " << monto20 << endl;
    cout << "la cantidad de billetes de S/.10 devueltos son: " << monto10 << endl;
    cout << "la cantidad de monedas de S/.5 devueltos son: " << monto5 << endl;
    cout << "la cantidad de monedas de S/.2 devueltos son: " << monto2 << endl;
    cout << "la cantidad de monedas de S/.1 devueltos son: " << monto1 << endl;
    //Impresion en decimales
    cout << "la cantidad de monedas de S/0.50 devueltos son: " << centimos50 << endl;
    cout << "la cantidad de monedas de S/0.20 devueltos son: " << centimos20 << endl;
    cout << "la cantidad de monedas de S/0.10 devueltos son: " << centimos10 << endl;
    //Impresion sobra
    if (centimos % 10 > 0)
    {
        cout << "Lamentamos decirle que le sobran: S:/0." << *sobra<< " y las monedas de 0.5 y 0.1 centimos ya no son vigentes" << endl;
    }
}

int main()
{
    long double x = 0.0;
    cout << "ingrese un monto, en caso de ser decimal usar el (.):"<< endl;
    cin >> x;
    cout << fixed << setprecision(2);
    cout << "el valor de en es: S/."<< x << endl;
    plata(x);
    return 0;
}