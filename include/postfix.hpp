#include "stack.hpp"
#include <map>
#include <string.h>

using namespace std;

template<ValType> 
class Postfix
{
private:
	Stack<ValType> operators;
	Stack<ValType> arguments;

	int IsOperator(char) const;
	int IsArgument(char) const;
	char* Postfix(char);
public:
	Postfix()
	~Postfix();
};

template<class ValType>
Postfix<ValType>::Postfix()
{
	operators = new Stack<ValType>();
	arguments = new Srack<ValType>();
}

template<class ValType>
Postfix<ValType>::~Postfix()
{
	delete operators;
	delete arguments;
}

template<ValType>
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

template<ValType>
int Postfix<ValType>::IsArgument(char value)
{
	if((IsOperator) || (value == ' '))
		return 0;
	return 1;
}

template<ValType>
char* Postfix<ValType>::Postfix(char *str)
{
	map <char, int> priority;
	priority ['*'] = 3;
	priority ['/'] = 3;
	priority ['+'] = 2;
	priority ['-'] = 2;
	priority ['('] = 1;
	priority ['='] = 0;

	char value;

	for (int i = 0; i < str.length(); i++)
	{
		value = str[i];
		
		if(IsArgument(values))
		{
			if(value == ')')
			{
				while ((!operators.IsEmpty()) && (operators.GetValue() != '('))
					arguments.Push(operators.Pop());
				if (operators.IsEmpty())
					throw ("Error : the brakets are not closed");
				operators.Pop();
				continue;
			}
			else
				arguments.Push(values);
		}
		
		if(IsOperator(values)) 
		{
			if ((!operators.IsEmpty()) && (priority[value] <= priority[operators.GetValue()]) && (value != '('))
				while ((!operators.IsEmpty()) && (priority[value] <= priority[operators.GetValue()]))
					arguments.Push(operators.Pop());	
			operators.Push(value);
			continue;
			if ((!operators.IsEmpty()) && (priority[value] > priority[operators.GetValue()]))
				operators.Push(values);
			if (value == '('))
				operators.Push(values);
		}
	}

	if (operators.GetValue() == '(')
		throw ("Error : the brakets are not closed");

	if (arguments.IsEmpty())
		throw ("Error : no data");
	
	char *string_result;
	char *tmp;

	while(!argument.IsEmpty()) 
	{
		tmp = argument.Pop();
		string_result.PushStart(0, tmp);
	}
	return string_result;
}
