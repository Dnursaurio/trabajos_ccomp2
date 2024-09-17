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

void Split(int *ini, int *fin, int A[10])
{
	//1. chequeamos si el nro al inicio es menor que el del final
	while (ini < fin)
	{
		if (*ini % 2 != 0)
		{
			int temp = *fin;
			for (int* r = fin; r > ini; r--)
			{
				*r = *(r - 1);
			}
			*ini = temp;

			fin--;
		}
		ini++;
	}	
	int *j = A;
	int *h = A + 4;
	while (*j > *h && (*j%2 == 0 && *h%2==0))
	{
		int temp = *h;
		*h = *j;
		*j = temp;
		j++;
		h--;
	}
}
//funcion principal

void  print(int * i, int A[10])
{
	for (int* i = A; i < A + 10; i++)
	{
		cout << *i << " ";
	}
	cout<<endl;
}
int main()
{
	int A[10] = { 2,6,8,12,20,1,3,7,11,15 };
	int *p = A;
	int *q = A + 5;
	int *x = A + 9;
	cout << "el array original es: ";
	print(p, A);
	cout << "el array con MERGE es: ";
	Merge(p, q);
	print(p, A);
	cout << "el array con SPLIT es: ";
	Split(p,x,A);
	print(p,A);

	return 0;
}