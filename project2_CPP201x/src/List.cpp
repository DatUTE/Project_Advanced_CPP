#include "List.h"
using namespace std;
template <class T>
List<T> ::List()
{
	index = 0;
	elements_[100];
}

template<typename T>
List<T>::~List()
{

}

template <class T>
void List<T>::add(const T& item)
{
	if (index < 100)
	{
		elements_[index] = item;
		index++;
	}
	else
	{
		cout << "Vuot qua so luong phan tu cho phep" << endl;
	}

}

template <class T>
T List<T>::get(int pos)
{
	if (pos < 100)
	{
		return elements_[pos];
	}
	else
	{
		cout << "Vuot qua so luong phan tu " << endl;
	}
	return {};
}

template<class T>
int List<T>::size()
{
	return index;
}

template<class T>
void List<T>::Swap(int i, int j)
{
	T a;
	a = elements_[i];
	elements_[i] = elements_[j];
	elements_[j] = a;
}