#include <iostream>
using namespace std;

//funcion Split
void Split(int* ini, int* fin, int A[10])
{
	//1. chequeamos si el nro al inicio es menor que el del final
	while (ini<fin)
	{
		if (*ini%2 != 0)
		{
			int temp = *ini;
			for (int *r = ini; r < fin; r++)
			{
				*r = *(r + 1);
			}
			*fin = temp;

			fin--;
		}
		ini++;
	}
}

int main()
{
	//establecemos el array
	int B[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* inicio = B;
	int* final = B + 9;
	Split(inicio, final,B);
	for (int *i = B; i < B+10; i++)
	{
		cout << *i<<" ";
	}
}