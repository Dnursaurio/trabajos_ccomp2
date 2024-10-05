#include <iostream>
using namespace std;

void print(int n, int A[])
{
	for (int p = 0; p < n; p++)
	{
		printf("%d ", A[p]);
	}
	cout << endl;
}

void cocktail(int *&ini, int *&fin)
{
	bool continuar = true;
	int* inicio = ini;
	int* final = fin;
	while (inicio < final)
	{
		continuar = false;
		for (int* extra = ini + 1; extra <= fin; extra++)
		{
			if (*ini > *extra)
			{
				swap(*ini,*extra);
				continuar = true;
			}
			ini++;
		}
		if (!continuar)
		{
			break;
		}
		continuar = false;
		fin--;
		for (int*extra2 = fin-1;extra2 >=inicio;extra2--)
		{
			if (*extra2 > *fin)
			{
				swap(*extra2,*fin);
				continuar = true;
			}
			fin--;
		}
		final--;
		fin = final;
		inicio++;
		ini = inicio;
	}
}

int main()
{
	int C[9] = {51,3,28,35,4,2,7,23,15};
	int *p = C;
	int *q = C + 8;
	cout << "el array original es: ";
	print(9, C);
	cout << "el valor del puntero inicial es: "<< *p << " el valor del puntero final es: "<< *q << endl;
	cout << "el array con Cocktail es: ";
	cocktail(p,q);
	print(9,C);
	cout << "el valor del puntero inicial con Cocktail es: " << *p << " el valor del puntero final con Cocktail es: " << *q << endl;
	return 0;
}