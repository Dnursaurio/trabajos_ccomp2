#include <iostream>
using namespace std;

template <class T>
struct nodo
{
	T valor;
	nodo* next;
	nodo(T val, nodo<T>* n = NULL)
	{
		valor = val;
		next = n;
	}
};

template <class T>
class LEC
{
	nodo<T>* head = NULL;
public:
	void add(T valor);
	void del(T valor);
	void print();
	bool find(T valor, nodo<T>*& pos);
	~LEC();
};

//aqui creamos sus metodos
template <class T>
bool LEC<T>::find(T valor, nodo <T>*& pos)
{
	pos = NULL;
	if (head == NULL)
	{
		return false;
	}
	nodo<T>* p = head;
	do
	{
		if (p->valor == valor)
		{
			return true;
		}
		p = p->next;
		pos = p;
	}while (p != head);
	return false;
}

template <class T>
void LEC<T>::add(T valor)
{
	nodo <T>* pos;

	if (!find(valor, pos))
	{
		if (!pos)
		{
			head = new nodo<T>(valor);
			head->next = head;
		}
		else
		{
			pos->next = new nodo<T>(valor, pos->next);
		}
	}
}

template <class T>
void LEC<T>::del(T valor)
{
	nodo<T>* temp; 
	nodo<T>* pos;
	if (find(valor,pos))
	{
		if (!pos)
		{
			temp = head;
			head = head->next;
		}
		else
		{
			temp = pos->next;
			pos->next = temp->next;
		}
		delete temp;
	}
}

template <class T>
void LEC<T>::print()
{
	
	if (head == NULL)
	{
		cout << "HEAD -> NULL" << endl;
		return;
	}
	cout << "HEAD -> ";
	nodo<T>* p = head;
	do
	{
		cout << p->valor << " -> ";
		p = p->next;
	}while (p != head);
	cout << "HEAD" << endl;
}

template <class T>
LEC<T>::~LEC()
{
	if (head != NULL)
	{
		nodo<T>* p = head;
		while (p != head)
		{
			nodo<T>* temp = p;
			p = p->next;
			delete temp;
		}
		head = NULL;
		cout << "destruccion" << endl;
	}
	
}

int main()
{
	//asi instancio un obj de la clase lista enlazada circular (LEC)
	LEC<int> lec;
	cout << "lista elazada circular vacia:" << endl;
	lec.print();
	cout << "anadiendo elementos:" << endl;
	cout << "1" << endl;
	lec.add(1);
	lec.print();
	cout << "7" << endl;
	lec.add(7);
	lec.print();
	cout << "5" << endl;
	lec.add(5);
	lec.print();
	cout << "eliminando elementos:" << endl;
	lec.del(5);
	lec.print();
	cout << "destruimos:" << endl;
	lec.~LEC();
	lec.print();
	return 0;
}