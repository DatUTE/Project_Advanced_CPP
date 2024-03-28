#pragma once
#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include"Setting.h"

template<class T>
class List {
private:
	T elements_[100];
	int index;
public:
	List();
	virtual ~List();
	void add(T const& item);
	T get(int pos);
	int size();
	void Swap(int i, int j);
};

#endif /* LIST_H_ */
template class List<Setting*>;


