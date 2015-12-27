#include <iostream>
#include "postfix.hpp"
#include <string>

using namespace std;

int main()
{
	string str;
	cout << "" << endl;
	getline(cin, str);
	Postfix<char> postfix;

	cout << endl << "String -> " << str << endl ;
	string postfix_str = postfix.PostfixString(str);
	cout << endl << "Postfix form -> " << postfix_str << endl;

	ResType res;
	try
	{
    res = postfix.Calculator(postfix_str);
	}
    catch (const exception &e) 
	{
        cout << e.what() << endl;
        return 1;
    }
    cout << "Result : " << res << endl ;
    return 0;
}