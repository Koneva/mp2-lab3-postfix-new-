#pragma once 

#include "list.hpp"
#include  <iostream>
#include <cstdlib> 

template <class ValType>
class Stack
{
private:
	List<ValType>* list;
public:
	Stack();
	Stack(const Stack<ValType>*);
	~Stack();

	int IsFull() const;
	int IsEmpty() const;
	void Push(ValType);
	ValType Pop();
	ValType GetValue();
	void Print() const;
};

//�����������
template<class ValType>
Stack<ValType>::Stack()
{
	list = new List<ValType>();
}

//����������� �����������
template<class ValType>
Stack<ValType>::Stack(const Stack<ValType>* stack)
{
	list = new List<ValType>(stack -> list);
}

//����������
template<class ValType>
Stack<ValType>::~Stack()
{
	delete list;
}

//�������� �� �������
template<class ValType>
int Stack<ValType>::IsFull() const
{
	Node<ValType> *node;
	try
	{
		node = new Node<ValType>;
	}
	catch(...)
	{
		return 1;
	}
	delete node;
	return 0;
}

//�������� �� �������
template<class ValType>
int Stack<ValType>::IsEmpty() const
{
	return (list -> GetFirst() == 0);
}

//�������� �������
template<class ValType>
void Stack<ValType>::Push(ValType key)
{
	if(IsFull())
		throw ("Stack is full");
	list -> PushStart(key);
}

//������ �������
template<class ValType>
ValType Stack<ValType>::Pop()
{
	if(IsEmpty())
		throw ("Stack is empty");
	ValType tmp = list -> GetFirst() -> key;
	list -> Remove(tmp);
	return tmp;
}

//������ � ��������
template<class ValType>
ValType Stack<ValType>::GetValue()
{
	if(IsEmpty())
		throw ("Stack is empty");
	return list -> GetFirst() -> key;
}

//������ �����
template<class ValType>
void Stack<ValType>::Print() const
{
	Stack<ValType>* stack = new Stack<ValType>(*this);
	while (!(stack -> IsEmpty()))
		cout << stack -> Pop() << endl ;
}