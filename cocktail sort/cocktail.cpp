#include <iostream>
using namespace std;

void cocktail(int *&ini, int *&fin, int C[9])
{
	while (*ini > *fin)
	{
		int temp = *ini;
		for (int *r = ini; r < fin; r++)
		{
			*r = *(r + 1);
		}
		*fin = temp;
		fin--;
	}
	int *t = fin;
	while (*t > *ini)
	{
		t--;
		int temp2 = *t;
		if (*ini > *t)
		{
			for (int *r = t; r > ini; r--)
			{
				*r = *(r - 1);
			}
			*ini = temp2;
			ini++;
		}
	}
	int *s = fin - 1;
	while (*s > *fin)
	{
		int temp3 = *fin;
		for (int *r = fin; r > s; r--)
		{
			*r = *(r - 1);
		}
		*s = temp3;
		fin--;
	}
	int* j = ini + 1;
	while (*j > *s)
	{
		int temp4 = *s;
		for (int* r = s; r > j; r--) 
		{
			*r = *(r - 1);
		}
		*j = temp4;
	}
	int *o = fin + 1;
	int temp5 = *o;
	*o = *fin;
	*fin = temp5;
	int* h = fin - 1;
	int tempfinal = *fin;
	*fin = *h;
	*h = tempfinal;
}

void print(int*p, int A[9])
{
	for (p = A; p < A+9; p++)
	{
		cout << *p<<" ";
	}
	cout << endl;
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
	cocktail(p,q,C);
	print(p,C);
	cout << "el valor del puntero inicial con Cocktail es: " << *p << " el valor del puntero final con Cocktail es: " << *q << endl;
	return 0;
}