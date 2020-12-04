#include <iostream>
#include "Stack/Stack.h"
using namespace std;

/**
 * See that for loop bro ?
 * It iterates through string char by char
 * see that loop body bro ?
 * it's all constant to n which is length of
 * string
 * Thats it, therefore the time complexity is
 * theta(n) ;)
 */
string postfixToPrefix(string postfix)
{
	Stack<string> stackEAziz;

	for(char c : postfix)
	{
		if(c=='+' || c=='-' || c=='*' || c=='/')
		{
			string op1 = stackEAziz.top();
			stackEAziz.pop();
			string op2 = stackEAziz.top();
			stackEAziz.pop();
			stackEAziz.push(c + op2 + op1);
		} else 
			stackEAziz.push(string{c});

	}

		string result = "";
		while (!stackEAziz.isEmpty())
		{
			result += stackEAziz.top();
			stackEAziz.pop();
		}
		return result;
}
int main()
{
	string potfix = "ab+c-";
	cout << postfixToPrefix(potfix) << endl;
	return 0;
}
