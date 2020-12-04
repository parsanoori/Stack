#include <iostream>
#include "Stack/Stack.h"
using namespace std;

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
