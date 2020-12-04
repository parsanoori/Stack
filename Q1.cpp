#include "Stack/Stack.h"
#include <iostream>
using namespace std;

template <typename T>
class Kin3Stacks {
	struct Holder {
		int index;
		T meghdar;
	};
	Stack<int> shomareStack;
	Stack<T> maghadir;
	Stack<Holder> temp;

    public:
	void push(const T& data, int koja)
	{
		maghadir.push(data);
		shomareStack.push(koja);
	}

	void pop(int azKodoom)
	{
		while (!maghadir.isEmpty()) {
			if(azKodoom ==  shomareStack.top()){
				maghadir.pop();
				shomareStack.pop();
				break;
			}

			temp.push(Holder{shomareStack.top(),maghadir.top()});
			shomareStack.pop();
			maghadir.pop();
		}

		if (maghadir.isEmpty())
			cout << "Asan in stack e nist" << endl;

		while(!temp.isEmpty())
		{
			maghadir.push(temp.top().meghdar);
			shomareStack.push(temp.top().index);
			
			temp.pop();
		}
	}

	T top(int azKodoom)
	{
		T tmp;
		while (!maghadir.isEmpty()) {
			if(azKodoom ==  shomareStack.top()){
				tmp = shomareStack.top();
				break;
			}

			temp.push(Holder{shomareStack.top(),maghadir.top()});
			shomareStack.pop();
			maghadir.pop();
		}

		if (maghadir.isEmpty())
			cout << "Asan in stack e nist" << endl;

		while(!temp.isEmpty())
		{
			maghadir.push(temp.top().meghdar);
			shomareStack.push(temp.top().index);
			
			temp.pop();
		}

		return tmp;
	}
};

int main()
{
	Kin3Stacks<int> s;
	
	s.push(1,1);
	s.push(2,2);
	s.push(3,3);

	cout << s.top(2) << endl;

}
