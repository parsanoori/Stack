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
	newStack.pop();
	newStack.push(3);
	std::cout << newStack.top() << endl;
	std::cout << newStack.isEmpty() << std::endl;
	newStack.pop();
	std::cout << "isEmpty : " << newStack.getSize() << std::endl;
	std::cout << newStack.isEmpty() << std::endl;
	return 0;
}
