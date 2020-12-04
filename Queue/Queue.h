#ifndef CLASS_QUEUE_HEADER
#define CLASS_QUEUE_HEADER
#include <iostream>

template <typename T>
class Queue{
	struct Node{
		T data;
		struct Node* behind = nullptr;
	};

	struct Node* front_ptr;
	struct Node* rear_ptr;

	int size= 0;
	
	public:

	void enqueue(const T& data);
	const T& dequeue();
	const T& front();
	const T& rear();
	bool isEmpty();
	int getSize();


};

#include "Queue.cpp"

#endif
