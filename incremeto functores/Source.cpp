#include <iostream>
using namespace std;

struct increment
{
	int valor;
	increment(int m) :valor(m) {};
	int operator()(int a)
	{
		return(valor + a);
	}
};

void transform(int* ini, int* fin, increment c)
{
	for (int* d = ini; d < fin; d++)
	{
		*d = c(*d);
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int anadir = 5;

	transform(arr, arr + n, increment(anadir));


	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}