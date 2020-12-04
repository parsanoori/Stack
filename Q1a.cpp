#include "Stack/Stack.h"
#include <algorithm>
#include <exception>
#include <iostream>

/**
 * It isn't possible for both of them to be 
 * optimom hence I first optimize enque and 
 * second optimize deque
 */
template <typename T>
class QueueUsingStackOptimizedForEnque {
	//std::stack<T> stack1;
	//std::stack<T> stack2;
	Stack<T> stack1;
	Stack<T> stack2;

    public:
	void enqueue(const T& data)
	{
		stack1.push(data);
	}
	/**
	 * Due to transport of eleements to stack 2
	 * and return n-1 of the to stack 1
	 * the order af this nigga is O(n)
	 */
	const T dequeue()
	{
		int size = 0;
		while (!stack1.isEmpty()) {
			stack2.push(stack1.top());
			stack1.pop();
			size++;
		}
		const T tmp = stack2.top();
		stack2.pop();
		while (!stack2.isEmpty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
		return tmp;
	}

	/**
 	* Due to transport of eleements to stack 2
 	* and return n-1 of the to stack 1
 	* the order af this nigga is O(n)
 	*/
	const T& front()
	{
		while (!stack1.isEmpty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		const T& tmp = stack2.top();
		while (!stack2.isEmpty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
		return tmp;
	}
	const T& rear()
	{
		return stack1.top();
	}
};

template<typename T>
class QueueUsingStackOptimomForDequeue{
	Stack<T> stack1;
	Stack<T> stack2;
	public:
	void enqueue(const T& data)
	{
		while (!stack2.isEmpty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
		stack1.push(data);	
		while (!stack1.isEmpty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
	}

	const T dequeue()
	{
		T tmp =stack2.top();
		stack2.pop();
		return tmp;
	}

	const T front()
	{
		return stack2.top();
	}


	const T rear()
	{
		while (!stack2.isEmpty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
		const T result = stack1.top();
		while (!stack1.isEmpty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		return result;
	}
};

int main()
{
	QueueUsingStackOptimizedForEnque<int> q;
	q.enqueue(1);
	q.enqueue(2);
	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;

	QueueUsingStackOptimomForDequeue<int> q2;
	q2.enqueue(1);
	q2.enqueue(2);
	std::cout << q2.dequeue() << std::endl;
	std::cout << q2.dequeue() << std::endl;


}
