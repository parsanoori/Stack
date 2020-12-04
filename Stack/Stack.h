#ifndef CLASS_STACK
#define CLASS_STACK

#include <exception>
#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
	struct Node {
		T data;
		struct Node* previous;
	};
	struct Node* top_ptr = nullptr;
	int size = 0;

    public:
	void pop();

	void push(const T& data);

	const T& top();

	bool isEmpty();
	int getSize();
};
#include "Stack.cpp"
#endif
