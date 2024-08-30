#include <iostream>
#include <string>
using namespace std;

string convertir(unsigned int x)
{
	//esta cadena guardara los nombres de los numeros;
	string palabra;

	//defimios el rango del problema
	if (x < 1 || x > 999999)
	{
		palabra = "fuera de rango, te lo especifique y no hiciste caso :(";
		//este return evitara que nos devuelva el mesaje y un nombre numero raro
		return palabra;
	}
	
	/* aplicamos los nombres clave para los numeros antes del sufijo "mil" (esto estaba al final pero lom puse aqui por que al final del codigo no funcionaba, 
	solo devolvia el nombre de los ultimos dos digitos)*/
	if (x >= 1000)
	{
		int millar = x / 1000;
		int masresto = x % 1000;

		if (millar == 1)
		{
			palabra = "mil";
		}
		else
		{
			palabra = convertir(millar) + " mil";
			//añadimos la logica para el caso de los "un mil"
			if (palabra.find("uno mil") != string::npos)
			{
				palabra.replace(palabra.find("uno mil"),7,"un mil");
			}
		}

		if (masresto != 0)
		{
			palabra += " " + convertir(masresto);
		}
		//hago este retorno para evitar que el programa devuelva el nombre de los ultimos dos digitos despues del nombre de los miles
		return palabra;
	}
	//primero a�adimos nombres clave (luego los reciclaremos en palabras mas largas)
	//A estos los llamare nombre cambiantes
	if(x<=20)
	{
		//casos menosres de veinte (los mas cambiantes)
		switch (x)
		{
			case 1:palabra = "uno"; break;
			case 2:palabra = "dos";break;
			case 3:palabra = "tres";break;
			case 4:palabra = "cuatro";break;
			case 5:palabra = "cinco";break;
			case 6:palabra = "seis";break;
			case 7:palabra = "siete";break;
			case 8:palabra = "ocho";break;
			case 9:palabra = "nueve";break;
			case 10: palabra = "diez";break;
			case 11: palabra = "once"; break;
			case 12: palabra = "doce"; break;
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
	else if (x < 100)
	{
		//calculamos las decenas
		int decenas = x / 10;
		int unidades = x % 10;
		//a�adimos los sufijos para las decenas
		switch (decenas)
		{
			case 2: palabra = (unidades == 0)? "veinte" : "veinti"; break;
			case 3: palabra = "treinta"; break;
			case 4: palabra = "cuarenta"; break;
			case 5: palabra = "cincuenta"; break;
			case 6: palabra = "sesenta"; break;
			case 7: palabra = "setenta"; break;
			case 8: palabra = "ochenta"; break;
			case 9: palabra = "noventa"; break;
		}
		if (decenas == 2 && (unidades != 0))
		{
			palabra += convertir(unidades);
		}
		else if (unidades != 0)
		{
			palabra += " y " + convertir(unidades);
		}
	}
	else if (x >= 100)
	{
		//usamos las variables para calcular las centenas y lso que reste del numero
		int centenas = x / 100;
		//esto nos ayudara de manera recursiva a llamar a los que falte del numero
		int resto = x % 100;
		//switcheamos los nombres clave
		switch (centenas)
		{
			//aqui definimos las diferecnia entre "cien" y sus superiores
			case 1: palabra = (resto == 0) ? "cien" : "ciento"; break;
			case 2: palabra = "doscientos"; break;
			case 3: palabra = "trescientos"; break;
			case 4: palabra = "cuatrocientos"; break;
			case 5: palabra = "quinientos"; break;
			case 6: palabra = "seiscientos"; break;
			case 7: palabra = "setecientos"; break;
			case 8: palabra = "ochocientos"; break;
			case 9: palabra = "novecientos"; break;
		}

		if (resto != 0)
		{
			palabra += " " + convertir(resto);
		}
	}
	return palabra;
}
//llamanos a nuestra mega funcion en la funcion principal
int main()
{
	unsigned int x = 0;
	cout << "ingrese un numero entre 1 y 999999: "<< endl;
	//le pedimos al usuario el numero
	cin >> x;
	string resultado = convertir(x);
	cout << resultado<<endl;
	return 0;
}