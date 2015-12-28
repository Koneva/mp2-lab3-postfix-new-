#include "postfix.hpp"

#include <gtest.h>

TEST(Postfix, PostfixString_return_true)
{
	string str = "a*(b+c-d)+(d/(f-c)-(k+l)/s)*k";
	string postfix_str = "abc+d-*dfc-/kl+s/-k*+";
	Postfix<char> p;
	EXPECT_EQ(p.PostfixString(str), postfix_str);
} 
