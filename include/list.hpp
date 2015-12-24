#pragma once

#include <iostream>

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
	List(const List<ValType>*);
	~List();

	void PushStart(ValType key);
	void PushAfter(ValType key, Node<ValType> *elem); 
	void PushBefore(ValType key, Node<ValType> *elem);
	void PushEnd(ValType key);
	Node<ValType>* Search(ValType key); 
	Node<ValType>* GetFirst()const;
	void Remove(ValType key);
};

//�����������
template<class ValType>
List<ValType>::List()
{
	First = 0;
}

//����������� �����������
template<class ValType>
List<ValType>::List(const List<ValType> *list)
{
	First = 0;
	Node<ValType>* first = list.First;
	while (first != 0)
	{
		PushEnd(first -> key);
		first = first -> next;
	}
}

//����������
template<class ValType>
List<ValType>::~List()
{
	delete First;
}

//������� � ������
template<class ValType>
void List<ValType>::PushStart(ValType key)
{
	Node<ValType>* node = new Node<ValType>();
	node -> key = key;
	node -> next = First;
	First = node;
}

//������� � �����
template<class ValType>
void List<ValType>::PushEnd(ValType key)
{
	Node<ValType>* node = First;
	if(!First)
	{
		PushStart(key);
		return;
	}
	while (First -> Next != 0)
		First = First -> Next;
	node -> Next = new Node<ValType>;
	node = node -> Next;
	node -> key = key;
	node -> Next = 0;
}

//������� ����� ��������
template<class ValType>
void List<ValType>::PushAfter(ValType key, Node<ValType> *elem)
{
	Node<ValType>* node = search(key);
	if(node -> Next != 0)
	{
		elem -> Next = node -> Next;
		node -> Next = elem;
	}
	else
		PushEnd(push_key);
}

//������� �� ��������
template<class ValType>
void List<ValType>::PushBefore(ValType key, Node<ValType> *elem)
{
	Node<ValType>* node = First;
	Node<ValType>* node_next  = node -> Next;

	while ((node_next -> next != 0) && (node-_next -> key != key))
	{
		node = node_next;
		node_next = node_next -> Next;
	}
	if((node_next -> next == 0) && (node_next -> key != key))
		throw ("This element isn't found");
	elem -> Next = node_next;
	node -> Next = elem;
}

//�����
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

//������ � ������� ��������
template<class ValType>
Node<ValType>* List<ValType>::GetFirst()const
{
	return First;
}

//�������� ��������
template<class ValType>
void List<ValType>::Remove(ValType key)
{
	if(First == 0)
		throw ("List is empty");
	First = First -> Next;
}