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
	Stack(const Stack<ValType>&);
	~Stack();

	int IsFull() const;
	int IsEmpty() const;
	void Push(ValType);
	ValType Pop();
	ValType GetValue();
	void Print() const;

    int operator== (const Stack&)const;
    int operator!= (const Stack&)const;
};

//конструктор
template<class ValType>
Stack<ValType>::Stack()
{
	list = new List<ValType>();
}

//конструктор копирования
template<class ValType>
Stack<ValType>::Stack(const Stack<ValType>& stack)
{
	list = new List<ValType>(*stack.list);
}

//деструктор
template<class ValType>
Stack<ValType>::~Stack()
{
	delete list;
}

//проверка на полноту
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

//проверка на пустоту
template<class ValType>
int Stack<ValType>::IsEmpty() const
{
	return (list -> GetFirst() == 0);
}

//вставить элемент
template<class ValType>
void Stack<ValType>::Push(ValType key)
{
	if(IsFull())
		throw ("Stack is full");
	list -> PushStart(key);
}

//изъять элемент
template<class ValType>
ValType Stack<ValType>::Pop()
{
	if(IsEmpty())
		throw 
		("Stack is empty");
	ValType tmp = list -> GetFirst() -> key;
	list -> Remove(tmp);
	return tmp;
}

//доступ к значению
template<class ValType>
ValType Stack<ValType>::GetValue()
{
	if(IsEmpty())
		throw 
		exception ("Stack is empty");
	return list -> GetFirst() -> key;
}

//печать стека
template<class ValType>
void Stack<ValType>::Print() const
{
	Stack<ValType>* stack = new Stack<ValType>(*this);
	while (!(stack -> IsEmpty()))
		cout << stack -> Pop() << endl ;
}


template <class ValType>
int Stack<ValType>::operator== (const Stack& stack)const
{
	return (*list == *(stack.list));
}

template <class KeyType>
int Stack<KeyType>::operator!= (const Stack& stack)const
{
	return (*list != *(stack.list));
}