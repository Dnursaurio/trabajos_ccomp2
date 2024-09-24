//incluicones
#include <iostream>
using namespace std;
//funcion merge
void Merge(int *p,int *q)
{
	int *fin = q + (q - p);

	while(p<q && q<fin)
	{
		if(*p > *q)
		{
			int temp = *q;
			for(int* r = q; r>p; r--)
			{
				*r = *(r-1);
			}
			*p = temp;
			q++;
		}
		p++;
	}
}

void Split(int *ini, int *fin)
{
	//al detectar q como segundo puntero fin esta al medio de array
	//acomodamos el final donde debe de ser
	int *finaltrue = (fin + (fin - ini));//aqui esta fuera del array
	finaltrue--;//ahora esta al final del arreglo
	while (ini < fin)
	{
		if (*ini % 2 != 0)
		{
			int temp = *ini;
			for (int *r = ini; r < finaltrue; r++)
			{
				*r = *(r + 1);
			}
			*finaltrue = temp;
		}
		else
		{
			ini++;
		}
	}
}
//funcion principal

void  print(int * i, int A[10])
{
	for (int *i = A; i < A + 10; i++)
	{
		cout << *i << " ";
	}
	cout<<endl;
}
int main()
{
	int A[10] = { 2,6,8,12,20,1,3,7,11,15 };
	//puntero al inicio
	int *p = A;
	//puntero al medio
	int *q = A + 5;
	cout << "el array original es: ";
	print(p, A);
	cout << "el array con MERGE es: ";
	Merge(p, q);
	print(p, A);
	cout << "el array con SPLIT es: ";
	Split(p,q);
	print(p,A);

	return 0;
}