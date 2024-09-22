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
	while (ini < fin)
	{
		if (*ini > *fin)
		{
			int temp = *ini;
			for (int* r = ini; r < fin; r++)
			{
				*r = *(r + 1);
			}
			*fin = temp;
			fin--;
		}
		if (*ini < *fin)
		{
			ini++;
		}
	}
	//esto es para arrelgar el 2 lo anterior ordena casi todo
	int *inicio2 = ini - 4;
	int *final2 = fin - 2;
	while (*inicio2 > *final2)
	{
		int tempfinal = *final2;
		for (int *t = final2; t > inicio2; t--)
		{
			*t = *(t - 1);
		}
		*inicio2 = tempfinal;
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