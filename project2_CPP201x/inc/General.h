#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>


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
	void set_timeZone(const string& data);
	void set_language(const string& data);
private:
	string timeZone;
	string language;
};




