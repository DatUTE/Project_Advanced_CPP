#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include<sstream>


using namespace std;
class General
{
public:
	General();
	~General();
	void nhapThongTin(int a);
	void xuatThongTin();
	string get_language();
	string get_timeZone();
	void set_timeZone(string data);
	void set_language(string data);
	string toStringGeneral();
private:
	string timeZone;
	string language;
};








