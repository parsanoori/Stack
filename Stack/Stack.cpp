
#include "Stack.h"

template <typename T>
void Stack<T>::pop()
{
	if (!top_ptr)
		return;
	Node* tmp = top_ptr;
	top_ptr = tmp->previous;
	delete tmp;
	size--;
}

template <typename T>
void Stack<T>::push(const T& data)
{

	if (!top_ptr)
		top_ptr = new Node { data, nullptr };
	Stack<T>::Node* new_node = new Node { data, top_ptr };
	top_ptr = new_node;
	size++;
}

template <typename T>
const T& Stack<T>::top()
{
	if (!top_ptr)
		throw new std::runtime_error("Stack is empty");
	return top_ptr->data;
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return !top_ptr;
}

template <typename T>
int Stack<T>::getSize(){
	return size;
}
