#pragma once 

#include "list.hpp"

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
};

//конструктор
template<class ValType>
Stack<ValType>::Stack()
{
	list = new List<ValType>();
}

//конструктор копирования
template<class ValType>
Stack<ValType>::Stack(const Stack<ValType>* stack)
{
	list = new List<ValType>(stack -> list);
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
		throw ("Stack is empty");
	ValType tmp = list -> GetFirst() -> key;
	List -> Remove(tmp);
	return tmp;
}

//доступ к значению
template<class ValType>
ValType Stack<ValType>::GetValue()
{
	if(IsEmpty())
		throw ("Stack is empty");
	return list -> GetFirst() -> key;
}