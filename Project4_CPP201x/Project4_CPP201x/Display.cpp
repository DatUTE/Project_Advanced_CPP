#include "Display.h"
#include <iomanip>
vector<CommonInfo> dispList;

int checkNum2();
Display::Display()
{
	light_level = 0;
	screen_light_level = 0;
	taplo_light_level = 0;
}

Display::~Display()
{

}

int Display::get_light_level() {
	return 	light_level;
}

int Display::get_screen_light_level() {
	return  screen_light_level;
}

int Display::get_taplo_light_level() {
	return  taplo_light_level;
}

void Display::set_light_level(int data)
{
	this->light_level = data;
}

void Display::set_screen_light_level(int data) {
	this->screen_light_level = data;
}

void Display::set_taplo_light_level(int data) {
	this->taplo_light_level = data;
}

void Display::nhapThongTin() {
	cout << " \n--- Nhap thong tin Display --- " << endl;
	cout << "Enter light level: ";
	set_light_level(checkNum2());
	cout << "Enter screen light level: ";
	set_screen_light_level(checkNum2());
	cout << "Enter taplo light level: ";
	set_taplo_light_level(checkNum2());
}

void Display::xuatThongTin() {
	cout << setw(15) << this->light_level << setw(10) << this->screen_light_level << setw(10) << this->taplo_light_level;
}
int checkNum2() {
	regex Display_level("[0-9]+");
	string s_Display_level = "";
	bool valid = true;
	do {
		getline(cin, s_Display_level);
		if (!regex_match(s_Display_level, Display_level)) {
			cout << "Input value follow number!!!\n";
			cout << "enter again: ";
			valid = false;
		}
		else
		{
			valid = true;
		}

	} while (!valid);
	return stoi(s_Display_level);
}
string Display::toStringDisplay()
{
	stringstream stm;
	stm << "Display: " << get_light_level() << "," << get_screen_light_level() << "," << get_taplo_light_level() << ";";
	return stm.str();
}

