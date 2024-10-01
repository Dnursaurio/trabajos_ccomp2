#include <iostream>
using namespace std;

void print(int*p, int A[9])
{
	for (p = A; p < A+9; p++)
	{
		cout << *p<<" ";
	}
	cout << endl;
}

void cocktail(int *&ini, int *&fin)
{
	for (int *ptrrec = ini+1; ptrrec < fin;ptrrec++)
	{
		if (*ini > *ptrrec)
		{
			int temp = *ini;
			*ini = *ptrrec;
			*ptrrec = temp;
		}
		ptrrec++;
		ini++;
	}
}

int main()
{
	int C[9] = {51,3,28,35,4,2,7,23,15};
	int *p = C;
	int *q = C + 8;
	cout << "el array original es: ";
	print(p, C);
	cout << "el valor del puntero inicial es: "<< *p << " el valor del puntero final es: "<< *q << endl;
	cout << "el array con Cocktail es: ";
	cocktail(p,q);
	print(p,C);
	cout << "el valor del puntero inicial con Cocktail es: " << *p << " el valor del puntero final con Cocktail es: " << *q << endl;
	return 0;
}