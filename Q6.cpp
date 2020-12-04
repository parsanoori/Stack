#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T, int n>
class QandS {
	T arr[n];
	int sarESaf = n - 1;
	int tahESaf = n - 1; // inja sareshe
	int sarEStack = 0;
	void bepaBeShokhNarim()
	{
		if (sarEStack == tahESaf + 1 && sarESaf == n - 1)
			throw std::runtime_error("Por shod haji vel kon");

		int delta = sarESaf - (n - 1);
		if (sarEStack == tahESaf + 1)
			for (int i = sarESaf; i >= tahESaf; i++)
				arr[i + delta] = arr[i];
	}
	void checkKonStackKhaliNabashe()
	{
		if (sarESaf == 0)
			throw std::runtime_error("Amoooooooo poshte khalie chi mikhai bar dari");
	}

    public:
	void push(const T& data)
	{
		bepaBeShokhNarim();
		arr[sarEStack++] = data;
	}

	void pop()
	{
		checkKonStackKhaliNabashe();
		sarESaf--;
	}

	T top()
	{
		checkKonStackKhaliNabashe();
		return arr[sarESaf - 1];
	}

	void enqueue(const T& data)
	{
		bepaBeShokhNarim();
		arr[tahESaf-1] = data;
	}

	T dequeue()
	{
		if (sarESaf == tahESaf)
			throw std::runtime_error("Amoooooooo saf khalieeeeeeea");
		return arr[sarESaf--];
	}
};
