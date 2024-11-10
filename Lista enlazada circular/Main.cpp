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
			pos = p;
			return true;
		}
		pos = p;
		p = p->next;
	}while (p != head);
	return false;
}

template <class T>
void LEC<T>::add(T valor)
{
	nodo <T>* pos = NULL;

	if (!find(valor, pos))
	{
		if (!pos)
		{
			head = new nodo<T>(valor);
			head->next = head;
		}
		else
		{
			if (valor > pos->valor)
			{
				pos->next = new nodo<T>(valor, pos);
			}
			else
			{
				pos = head;
				nodo<T>* tmp = pos;
				pos = pos->next;
				tmp->next = new nodo<T>(valor, pos);
			}
		}
	}
}

template <class T>
void LEC<T>::del(T valor)
{
	nodo<T>* temp = NULL; 
	nodo<T>* pos = NULL;
	if (find(valor,pos))
	{
		if (head == head->next)
		{
			delete head;
			head = NULL;
		}
		else if (pos == head && head->valor == valor)
		{
			temp = head;
			head = head->next;
			pos->next = head;
			delete temp;
		}
		else
		{
			temp = pos->next;
			pos->next = temp->next;
			delete temp;
		}
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
	lec.print();
	lec.add(1);
	lec.add(7);
	lec.add(5);
	lec.add(4);
	lec.add(3);
	lec.print();
	lec.del(4);
	lec.print();
	return 0;
}