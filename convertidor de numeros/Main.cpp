#include <iostream>
#include <string>
using namespace std;

int convertir(unsigned int x)
{
	//defimios el rango del problema
	if (x < 1 || x > 999999)
	{
		cout<<"fuera de rango";
	}
	//esta cadena guardara los nombres de los numeros;
	string palabra;
	//primero añadimos casos clave (luego los reciclaremos en palabras mas largas) 
	if(x<=20)
	{
		//casos menosres de veinte (los mas cambiantes)
		switch (x)
		{
			case 1:palabra = "uno";break;
			case 2:palabra = "dos";break;
			case 3:palabra = "tres";break;
			case 4:palabra = "cuatro";break;
			case 5:palabra = "cinco";break;
			case 6:palabra = "seis";break;
			case 7:palabra = "siete";break;
			case 8:palabra = "ocho";break;
			case 9:palabra = "nueve";break;
			case 10:palabra = "diez";break;
			case 11:palabra = "once"; break;
			case 12:palabra = "doce"; break;
			case 13: palabra = "trece"; break;
			case 14: palabra = "catorce"; break;
			case 15: palabra = "quince"; break;
			case 16: palabra = "dieciseis"; break;
			case 17: palabra = "diecisiete"; break;
			case 18: palabra = "dieciocho"; break;
			case 19: palabra = "diecinueve"; break;
			case 20: palabra = "veinte"; break;
		}
	}
	else if (x > 100)
	{
		//evaluamos las decenas y las unidades de los numeros
		int decenas = x / 10;
		int unidades = x % 10;
		//añadimos los sufijos para las decenas
		switch (decenas)
		{
			case 2: palabra = "veinti"; break;
			case 3: palabra = "treinta"; break;
			case 4: palabra = "cuarenta"; break;
			case 5: palabra = "cincuenta"; break;
			case 6: palabra = "sesenta"; break;
			case 7: palabra = "setenta"; break;
		}
	}
	return x;
}

int main()
{
	unsigned int x = 0;
	cin >> x;
	convertir(x);
	return 0;
}