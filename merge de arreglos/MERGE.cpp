//incluicones
#include <iostream>
using namespace std;
//funcion merge
void Merge(int *p,int *q,int A[10])
{
	while (p<q && q<A+10)
	{
		if (*p>*q)
		{
			//guardamos el valor de q
			int temp = *q;
			//hacemos el desplazamiento de manera que [(aqui iria el 1),2,6,...,20,3,..,15]
			for (int * r =	q;  r > p; --r)
			{
				*r = *(r - 1);
			}
			//colocamos el valor de q en el lugar donde esta el valor de p
			*p = temp;
			//avanzamos el puntero q
			q++;
		}
		else
			p++;
	}
}
//funcion principal
int main()
{
	int A[10] = { 2,6,8,12,20,1,3,7,11,15 };
	int *p = A;
	int *q = A + 5;
	cout<<"el arreglo original es: ";
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	Merge(p, q, A);
	cout<<endl;
	cout <<"el arreglo con MERGE es: ";
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}
	cout<<endl;
	return 0;
}