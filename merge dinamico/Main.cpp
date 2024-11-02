#include <iostream>
using namespace std;

template <class T>
struct  nodo
{
	T valor;
	nodo* next;
	nodo(T val, nodo<T> *n = NULL)
	{
		valor = val;
		next = n;
	}
};

template <class T>
void ArraytoLE(int* ini, int* fin, nodo<T>*&head)
{
	head = NULL;
	for (int* p = fin; p >= ini; p--)
	{
		head = new nodo<T>(*p,head);
	}
}

template <class T>
void print(nodo<T>*head)
{
	cout << "HEAD -> ";
	for (nodo<T> *p = head;p;p=p->next)
	{
		cout << p->valor << " -> ";
	}
	cout << "NULL" << endl;
}

template<class T>
void merge(nodo<T>*&A,nodo<T>*&B)
{
	nodo<T>* cabeza = nullptr;
	nodo<T>** referencia = &cabeza;

	while (A && B) 
	{
		if (A->valor < B->valor) 
		{
			*referencia = A;
			A = A->next;
		}
		else if (A->valor > B->valor) 
		{
			*referencia = B;
			B = B->next;
		}
		else 
		{  
			*referencia = A;
			A = A->next;
			B = B->next; 
		}
		referencia = &((*referencia)->next); 
	}

	*referencia = (A) ? A : B;

	A = cabeza;

	B = nullptr;
}

int main()
{
	int A[6] = {2,5,6,8,13,24};
	int* p = A + 0;
	int* q = A + 5;
	nodo<int>* LEA;
	int B[5] = {3,5,7,8,12};
	int* e = B + 0;
	int* k = B + 4;
	nodo<int>* LEB;
	ArraytoLE(p,q,LEA);
	print(LEA);
	ArraytoLE(e, k, LEB);
	print(LEB);
	merge(LEA,LEB);
	print(LEA);
	print(LEB);
}