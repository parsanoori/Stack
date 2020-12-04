#include "Queue/Queue.h"
#include <iostream>

template <typename T>
class StackUsingQueueOptimomForPush {
	Queue<T> q1;
	Queue<T> q2;

    public:
	void push(const T& data)
	{
		q1.enqueue(data);
	}

	void pop()
	{
		while(!q1.isEmpty())
			q2.enqueue(q1.dequeue());
		while(q2.getSize() > 1)
			q1.enqueue(q2.dequeue());
	}

	T top()
	{
		return q1.rear();
	}
};



template <typename T>
class StackUsingQueueOptimomForPop {
	Queue<T> q1;
	Queue<T> q2;

    public:
	void push(const T& data)
	{
		q1.enqueue(data);
		while(!q2.isEmpty())
			q1.enqueue(q2.dequeue());
		while(!q1.isEmpty())
			q2.enqueue(q1.dequeue());

	}

	void pop()
	{
		q2.dequeue();
	}

	T top()
	{
		return q2.front();
	}
};

int main()
{
	StackUsingQueueOptimomForPop<int> s1;
	s1.push(1);
	s1.push(2);
	s1.pop();
	std::cout << s1.top() << std::endl;

	StackUsingQueueOptimomForPush<int> s2;
	s2.push(1);
	s2.push(2);
	s2.pop();
	std::cout << s2.top() << std::endl;
}
