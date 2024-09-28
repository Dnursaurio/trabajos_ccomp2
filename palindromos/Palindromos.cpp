#include <iostream>
#include <string>
using namespace std;

void LOWERCASE(char* p /*esto crea un puntero al inicio del array A*/)
{
	for (; *p; p++)
	{
		if (*p >= 65 && *p <= 90)
		{
			*p += 32;
		}
	}
}

void NOSPACE(char *p)
{
	char *q = p;
	while (*p)
	{
		if (*p != ' ')
		{
			*q++ = *p;
		}
		p++;
	}
	*q = '\0';
}

bool PALINDROMO(char *p)
{
	LOWERCASE(p);
	NOSPACE(p);
	cout << p << endl;
	char *q = p; // guardamos p
	for (; *q; q++); //nos vamos al final de array
	q--; //ultimo termino del array
	while (p < q)
	{
		if (*p != *q)
		{
			cout << "no es un palindromo, gil"<<endl;
			return false;
		}
		p++;
		q--;
	}
	cout << "es un palindromo, bien hecho crack" << endl;
	return true;
}

int main()
{
	//creamos un array con caracteres
	char A[] = "amo la paloma";
	cout << "la frase original es: " << A << endl;
	PALINDROMO(A);
	char B[] = "bienvenido a Silent Hill";
	cout << "la frase original es: " << B << endl;
	PALINDROMO(B);
	char C[] = "anita lava la tina";
	cout << "la frase original es: " << C << endl;
	PALINDROMO(C);
	return 0;
}