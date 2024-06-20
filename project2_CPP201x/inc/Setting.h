#pragma once
#ifndef SETTING_H_
#define SETTING_H_

#include <iostream>
#include <iomanip>
#include <memory>
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
	void setGeneral(General* p_general);
	General* getGeneral();
	void setSound(shared_ptr<Sound> p_sound);
	shared_ptr<Sound> getSound();
	void setDisplay(Display* p_display);
	Display* getDisplay();
	void copyInfo(Setting* st);
private:
	shared_ptr<Sound> m_sound;
	General* m_general;
	Display* m_display;
};
#endif /* SETTING_H_ */

