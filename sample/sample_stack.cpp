#include "stack.hpp"

using namespace std; 

int main()
{
	Stack<int>* stack = new Stack<int>;

	cout << "Is the stack empty?" << endl ;
	cout << stack -> IsEmpty() << endl ;

	for (int i = 0; i < 10; i++)
		stack -> Push(i * 11);

	cout << "STACK" << endl ;
	stack -> Print();

	cout << "To retrieve the element" << endl ;
	stack -> Pop();
	stack -> Print();

	cout << "To add the element 100" << endl ;
	stack -> Push(100);
	stack -> Print();

	return 1;
}