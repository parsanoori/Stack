#include <iostream>
#include "Stack/Stack.h"
#include "Queue/Queue.h"
using namespace std;


template <typename T>
void reverseViaQ(Stack<T>& in)
{
	Queue<T> Qjoon;
	while(!in.isEmpty()){
		Qjoon.enqueue(in.top());
		in.pop();
	}
	while(!Qjoon.isEmpty())
		in.push(Qjoon.dequeue());
}

template <typename T>
void reverseVia2Stacks(Stack<T>& in)
{
	Stack<T> s1,s2;
	while(!in.isEmpty()){
		s1.push(in.top());
		in.pop();
	}

	while(!s1.isEmpty()){
		s2.push(s1.top());
		s1.pop();
	}

	while(!s2.isEmpty()){
		in.push(s2.top());
		s2.pop();
	}
}


int main()
{
	Stack<int> s;
	s.push(1);
	s.push(2);

	reverseViaQ(s);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();

	s.push(1);
	s.push(2);
	reverseVia2Stacks(s);

	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();


}
