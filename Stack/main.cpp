#include "Stack.h"
#include <iostream>

using namespace std;

template<typename T> class Stack;

int main()
{
	Stack<int> newStack{};
	newStack.push(1);
	newStack.push(2);
	cout << newStack.top() << endl;
	newStack.pop();
	cout << newStack.top() << endl;
	return 0;
}
