#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);

	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	return 0;
}
