#include "list.hpp"
#include <iostream>

using namespace std;

int main()
{
	List<int> *list;
	list = new List<int>;

	list -> Print();

	cout << "Insert at the beginning element '1' " << endl ;
	list -> PushStart(1);
	list -> Print();

	cout << "Insert at the end element '4' " << endl ;
	list -> PushEnd(4);
	list -> Print();

	cout << "Insert after '1' element '3'" << endl ;
	Node<int> *elem1 = new Node<int>;
	elem1 -> key = 3;
	list -> PushAfter(1, elem1);
	list -> Print();

	cout << "Insert befor '3' element '2' " << endl ;
	Node<int> *elem2 = new Node<int>;
	elem2 -> key = 2;
	list -> PushBefore(3, elem2);
	list -> Print();

	return 1;
}