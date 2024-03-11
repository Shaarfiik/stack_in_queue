#include <iostream>
#include <list>
#include <chrono>
using namespace std;
const int maxSize = 10000;

template<typename T>
struct stack_mass {
	T* hop;
	T mass[maxSize];
	int count_el = 0;

	void compl_arr(T el) {
		if (count_el == 0)
		{
			mass[0] = el;
			hop = &mass[0];
			count_el++;
		}
		else
		{
			if (count_el <= maxSize)
			{
				hop++;
				*hop = el;
				count_el++;
			}
			else
			{
				cout << "stack overflow\n";
			}
		}

	}

	T get_element() {

		if (count_el == 0)
		{
			cout << "stack empty!\n";
			return -1;
		}
		else
		{
			if (count_el == 1) {
				hop == nullptr;
				count_el--;
				return mass[0];
			}
			else
			{
				T el = *hop;
				hop--;
				count_el--;
				return el;
			}
		}

	}

};

template<typename Y>
struct queueMass {
	Y* first;
	Y* last;
	Y mass[maxSize];
	int count_el = 0;

	void add_el(Y el) {
		if (count_el == 0)
		{
			mass[0] = el;
			last = &mass[0];
			first = &mass[0];
			count_el++;
		}
		else
		{
			if (count_el < maxSize)
			{
				last++;
				*last = el;
				count_el++;
			}
			else
			{
				cout << "turn overflow\n";
			}
		}

	}

	Y get_el() {

		if (count_el == 0)
		{
			cout << "turn empty\n";
			return -1;
		}
		else
		{
			Y el = *first;
			first++;
			count_el--;
			return el;
		}
	}

};

template<typename M>
struct stack_list
{
	list<M> newList;
	M* hop;
	int count_el = 0;

	void add_el(M el) {
		if (count_el < maxSize) {
			newList.push_back(el);
			count_el++;
			hop = &newList.back();
		}
		else
		{
			cout << "stack overflow\n";
		}
	}

	M get_el() {
		if (count_el == 0)
		{
			cout << "stack empty!\n";
			return -1;
		}
		else
		{
			if (count_el == 1)
			{
				hop = nullptr;
				count_el--;
				return newList.back();
			}
			else
			{
				M el = *hop;
				newList.pop_back();
				hop = &newList.back();
				count_el--;
				return el;
			}
		}
	}
};


template <typename S>
struct queue_list {
	S* first;
	int count_el = 0;
	list<S> newList;

	void add_el(S el) {
		if (count_el == 0) {
			newList.push_back(el);
			count_el++;
			first = &newList.front();
		}
		else
		{
			if (count_el <= maxSize)
			{
				newList.push_back(el);
				count_el++;
			}
			else
			{
				cout << "turn overflow\n";
			}
		}
	}

	S get_el() {
		if (count_el == 0)
		{
			cout << "turn empty\n";
			return -1;
		}
		else
		{
			if (count_el == 1)
			{
				first = nullptr;
				count_el--;
				return newList.front();
			}
			else
			{
				S el = *first;
				newList.pop_front();
				first = &newList.front();
				count_el--;
				return el;
			}
		}
	}

};

int main() {
	setlocale(LC_ALL, "RU");

	cout << "queue arr\n" << endl;

	queueMass<int> queArr;

	auto startQuArr = chrono::high_resolution_clock::now();

	for (int i = 0; i < maxSize; i++) {
		queArr.add_el(i);
	}
	for (int j = 0; j < maxSize; j++) {
		cout << queArr.get_el() << endl;
	}

	auto endQuArr = chrono::high_resolution_clock::now();
	chrono::duration<double> duration = endQuArr - startQuArr;

	cout << "Время выполнения программы: " << duration.count() << " second" << endl;

	return 0;
}