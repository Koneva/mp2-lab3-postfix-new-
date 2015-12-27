#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

template<class ValType>
class Node
{
public:
	ValType key;
	Node* Next;
};

template<class ValType>
class List
{
private:
	Node<ValType>* First;
public:
	List();
	List(const List<ValType>&);
	~List();

	void PushStart(ValType key);
	void PushAfter(ValType key, Node<ValType> *elem); 
	void PushBefore(ValType key, Node<ValType> *elem);
	void PushEnd(ValType key);
	Node<ValType>* Search(ValType key); 
	Node<ValType>* GetFirst()const;
	void Remove(ValType key);
	void Print()const;

	int operator==(const List list)const;
    int operator!=(const List list)const;
};

//конструктор
template<class ValType>
List<ValType>::List()
{
	First = 0;
}

//конструктор копирования
template<class ValType>
List<ValType>::List(const List<ValType> &list)
{
	First = 0;
	Node<ValType>* first = list.First;
	while (first != 0)
	{
		PushEnd(first -> key);
		first = first -> Next;
	}
}

//деструктор
template<class ValType>
List<ValType>::~List()
{
	delete First;
}

//вставка в начало
template<class ValType>
void List<ValType>::PushStart(ValType key)
{
	Node<ValType>* node = new Node<ValType>();
	node -> key = key;
	node -> Next = First;
	First = node;
}

//вставка в конец
template<class ValType>
void List<ValType>::PushEnd(ValType key)
{
	Node<ValType>* node = First;
	if(!First)
	{
		PushStart(key);
		return;
	}
	while (node -> Next != 0)
		node = node -> Next;
	node -> Next = new Node<ValType>;
	node = node -> Next;
	node -> key = key;
	node -> Next = 0;
}

//вставка после элемента
template<class ValType>
void List<ValType>::PushAfter(ValType key, Node<ValType> *elem)
{
	Node<ValType>* node = Search(key);
	if(node -> Next != 0)
	{
		elem -> Next = node -> Next;
		node -> Next = elem;
	}
	else
		PushEnd(elem -> key);
}

//вставка до элемента
template<class ValType>
void List<ValType>::PushBefore(ValType key, Node<ValType> *elem)
{
	Node<ValType>* node = First;
	Node<ValType>* node_next  = node -> Next;

	while ((node_next -> Next != 0) && (node_next -> key != key))
	{
		node = node_next;
		node_next = node_next -> Next;
	}
	if((node_next -> Next == 0) && (node_next -> key != key))
		throw ("This element isn't found");
	elem -> Next = node_next;
	node -> Next = elem;
}

//поиск
template<class ValType>
Node<ValType>* List<ValType>::Search(ValType key)
{
	if (First == 0)
		throw ("List is empty");
	Node<ValType>* node = First;
	while((node != 0) && (node -> key != key))
		node = node -> Next;
	if(node == 0)
		throw ("This element isn't found");
	return node;
}

//доступ к первому элементу
template<class ValType>
Node<ValType>* List<ValType>::GetFirst()const
{
	return First;
}

//удаление элемента
template<class ValType>
void List<ValType>::Remove(ValType key)
{
	if(First == 0)
		throw ("List is empty");

    Node<ValType>* node =  Search(key);

	if (First -> key == key) {
        First = First -> Next;
        return;
    }

    Node<ValType>* first = First;
    while (first -> Next != node)
        first = first -> Next;
    first -> Next = node-> Next;
    delete node;
}

template<class ValType>
void List<ValType>::Print()const
{
	Node<ValType>* first = First;
	while (first != 0)
	{
		cout << first -> key << " ";
		first = first -> Next;
	}
	cout << endl << endl ;
}

template <class ValType>
int List<ValType>::operator==(const List list)const
{
    Node<ValType>* first1 = First;
    Node<ValType>* first2 = list.First;
    while ((first1 != 0) && (first2 != 0))
	{
        if(first1 -> key != first2 -> key)
            return 0;
        first1 = first1 -> Next;
        first2 = first2 -> Next;
    }

    if (first1 != first2)
        return 0;
    return 1;
}

template <class ValType>
int List<ValType>::operator!=(const List list)const
{
    return !(*this == list);
}