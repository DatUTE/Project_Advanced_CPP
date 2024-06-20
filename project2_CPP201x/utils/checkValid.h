#pragma once
#ifndef CHECKVALID_H_
#define CHECKVALID_H_
#include <regex>
#include <iostream>
#include "List.h"
using namespace std;

int check_input_setting(int n);
int check_input(int n);
char checkYorN();
// Check personalKey
int check_personalKey(const string& a_personalKey, List<Setting*>& listCar);


#endif /* Car_H_ */