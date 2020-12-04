#include "Stack/Stack.h"
#include <iostream>
using namespace std;

bool isParantheseCorrect(std::string reshte)
{
	Stack<char> stackEAziz;
	while (!reshte.empty()) {
		const char& underQ = reshte.front();
		if (underQ == '(' || underQ == '{' || underQ == '[')
			stackEAziz.push(underQ);
		else {
			if (underQ == ')' && stackEAziz.top() != '(')
				return false;
			else if (underQ == ']' && stackEAziz.top() != '[')
				return false;
			else if (underQ == '}' && stackEAziz.top() != '{')
				return false;
			stackEAziz.pop();
		}
		reshte.erase(0, 1);
	}
	return true;
}
int main()
{
	std::string dorost = "({[]})";
	std::cout << isParantheseCorrect(dorost) << std::endl;
	std::string ghalat = "(}";
	std::cout << isParantheseCorrect(ghalat) << std::endl;
	return 0;
}
