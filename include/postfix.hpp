#pragma once 

#include "stack.hpp"
#include <map>
#include <string>

using namespace std;

typedef float ResType;

template<class ValType> 
class Postfix
{
private:
	Stack<ValType> operators;
	Stack<ValType> arguments;

	int IsOperator(char) const;
	int IsArgument(char) const;
public:
	Postfix();
	~Postfix();

	string PostfixString(string);
	ResType Calculator(string);
};

template<class ValType>
Postfix<ValType>::Postfix()
{
//	operators = new Stack<ValType>();
//	arguments = new Srack<ValType>();
}

template<class ValType>
Postfix<ValType>::~Postfix()
{
	//delete operators;
	//delete arguments;
}

template<class ValType>
int Postfix<ValType>::IsOperator(char value) const
{
	switch (value)
	{
		case '*':
			return 1;
		case '/':
			return 1;
		case '+':
			return 1;
		case '-':
			return 1;
		case '(':
			return 1;
		case ')':
			return 1;
		case '=':
			return 1;
		default:
			return 0;
	}
}

template<class ValType>
int Postfix<ValType>::IsArgument(char value) const
{
	if((IsOperator(value)) || (value == ' '))
		return 0;
	return 1;
}

template<class ValType>
string Postfix<ValType>::PostfixString(string str)
{
	map <char, int> priority;
	priority ['*'] = 3;
	priority ['/'] = 3;
	priority ['+'] = 2;
	priority ['-'] = 2;
	priority ['('] = 1;
	priority [')'] = 1;
	priority ['='] = 0;

	char value;

	for(int i = 0; i < str.length(); i++)
	{
		value = str[i];

		if (value == ' ')
			continue;

		if (IsOperator(value))
		{
			if (priority[value] == 1)
			{
				if (value == ')')
				{
					while ((!operators.IsEmpty()) && (operators.GetValue() != '('))
						arguments.Push(operators.Pop());
					if (operators.IsEmpty())
					{
						throw exception("Error : Incorrect.");
					}
					operators.Pop();
				}
				else
				{
					operators.Push(value);
					continue;
				}
			}
			else
				if(!operators.IsEmpty())
				{
					if (priority[value] <= priority[operators.GetValue()])
					{
						while ((!operators.IsEmpty()) && (priority[value] <= priority[operators.GetValue()]))
							arguments.Push(operators.Pop());
						operators.Push(value);
					}
					else
						operators.Push(value);
				}
				else
					operators.Push(value);
		}
		else
			arguments.Push(value);
	}

	if (!operators.IsEmpty())
		while (!operators.IsEmpty())
			arguments.Push(operators.Pop());

	if (arguments.IsEmpty())
		throw ("Error : No data.");

	while (!arguments.IsEmpty())
		operators.Push(arguments.Pop());

	string string_result = "";

	while (!operators.IsEmpty())
		string_result +=operators.Pop();

	
	for(int i = 0; i < string_result.length(); i++)
	{
		value = string_result[i];

		if (value == '(')
			throw exception ("Error : Incorrect expression.");
	}

	return string_result;
}

template<class ValType>
ResType Postfix<ValType>::Calculator(string str)
{ 
	if (str == "")
		throw ("Error : The string is empty");

	ResType LeftOperand;
	ResType RightOperand;
	char elem;
	Stack<ResType> Result;
	ResType res;

	map<char, ResType> value;

	if (str[str.length() - 1] == '=')
	{
			value[str[0]] = 0;
	}

	for (int i = 0; i < str.length(); i++)
	{
		elem = str[i];

		if(IsArgument(elem))
		{
			if (!value.count(elem))
			{
				cout << "Enter the value of element :" << endl ;
				cout << elem << " = " ;
				cin >> value[elem] ;
			}
				Result.Push(value[elem]);
				continue;
		}
		else
		{
			RightOperand = Result.Pop();
			LeftOperand = Result.Pop();
			switch (elem)
			{
				case '+':
					Result.Push(LeftOperand + RightOperand);
					break;
				case '-':
					Result.Push(LeftOperand - RightOperand);
					break;
				case '*':
					Result.Push(LeftOperand * RightOperand);
					break;
				case '/':
					if (RightOperand == 0)
					{
						throw std::exception("Error : /0");
					}
					Result.Push(LeftOperand / RightOperand);
					break;
			}
		}
	}
	
	res = Result.Pop();
		
	if(!Result.IsEmpty())
	{
		throw 
		exception ("Error : Incorrect expression.");
	}
	return res;
}