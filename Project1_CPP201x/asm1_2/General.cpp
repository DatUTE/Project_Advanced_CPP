#include "General.h"
#include "CommonInfo.h"
#include<regex>
General::General()
{
	timeZone = "";
	language = "";
}

General::~General() {

}

void General::nhapThongTin(int a)
{
	
}

void General::xuatThongTin() {
	cout << setw(22) << timeZone << setw(10) << language;
}

string General::get_language() {
	return this-> language;
}

string General::get_timeZone() {
	return this -> timeZone;
}

void General::set_timeZone(string data) 
{
	this -> timeZone = data ;
}

void General::set_language(string data) {
	this -> language = data ;
}
