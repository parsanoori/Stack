#ifndef CLASS_QUEUE_CPP
#define CLASS_QUEUE_CPP

#include "Queue.h"
#include <stdexcept>

template <typename T>
void Queue<T>::enqueue(const T& data)
{
	Node* newNode = new Node { data, nullptr };
	if (size == 0) {
		rear_ptr = newNode;
		front_ptr = newNode;
	} else {
		rear_ptr->behind = newNode;
		rear_ptr = rear_ptr->behind;
	}
	size++;
}

template <typename T>
const T Queue<T>::dequeue()
{
	if (size == 0)
		throw std::runtime_error { "Queue is empty" };
	T& val = front_ptr->data;
	struct Node* second = front_ptr->behind;
	delete front_ptr;
	front_ptr = second;
	size--;
	return val;
}

template <typename T>
const T Queue<T>::front()
{
	return front_ptr->data;
}

template <typename T>
const T Queue<T>::rear()
{
	return rear_ptr->data;
}

template <typename T>
bool Queue<T>::isEmpty()
{
	return size == 0;
}

template <typename T>
int Queue<T>::getSize()
{
	return size;
}

#endif
