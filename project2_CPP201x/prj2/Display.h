#pragma once
#ifndef DISPLAY_H_
#define DISPLAY_H_
#pragma once
#include <iostream>
#include <string>
#include<regex>
using namespace std;

class Display
{
public:
	Display();
	~Display();
	void nhapThongTin();
	void xuatThongTin();
	int get_light_level();
	int get_screen_light_level();
	int get_taplo_light_level();
	void set_light_level(int data);
	void set_screen_light_level(int data);
	void set_taplo_light_level(int data);
private:
	int light_level;
	int screen_light_level;
	int taplo_light_level;
};

#endif /* DISPLAY_H_ */



