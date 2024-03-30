#pragma once
#ifndef SETTING_H_
#define SETTING_H_

#include <iostream>
#include <iomanip>
#include "Car.h"
#include "Sound.h"
#include "Display.h"
#include "General.h"

using namespace std;

class Setting : public Car
{
public:
	Setting();
	~Setting();
	void xuatThongTin();
	void nhapThongTin();
	void setGeneral(General* gen);
	General* getGeneral();
	void setSound(Sound* sound);
	Sound* getSound();
	void setDisplay(Display* disp);
	Display* getDisplay();
	void copyInfo(Setting* st);
	void Swap(int i, int j);
private:
	Sound* sound;
	General* general;
	Display* display;
};
#endif /* SETTING_H_ */


