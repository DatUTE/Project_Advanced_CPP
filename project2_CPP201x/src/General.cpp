#include "General.h"
#include "CommonInfo.h"
#include<regex>
General::General()
{
	timeZone = "(GMT+07:00)";
	language = "Vietnamese";
}

General::~General() {

}

void General::nhapThongTin(int a)
{

}

void General::xuatThongTin() {
	cout << setw(22) << get_timeZone() << setw(10) << get_language();
}

string General::get_language() {
	return this->language;
}

string General::get_timeZone() {
	return this->timeZone;
}

void General::set_timeZone(const string& data)
{
	this->timeZone = data;
}

void General::set_language(const string& data) {
	this->language = data;
}


