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
	/*segun geeksforgeeks usa 3 
	parametros uno que esta al incio del arreglo (ini),
	uno al final (fin) y uno delante del parametro inicial*/
	//usamos este parametro para dos tipos de recorrido uno hacia la derecha y otro a la izquierda
	//el bucle sera mientras la posicion de ini sea < a la de fin
	while (ini < fin)
	{
		//hacemos el recorrido hacia la derecha
		for (int *extra = ini + 1; extra <= fin; extra++) //aseguramos el recorrido
		{
			if (*ini > *extra)
			{
				swap(*ini,*extra);
			}
		}
		//retrocedemos el valor del final
		ini++;
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