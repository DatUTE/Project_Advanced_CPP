#include "Sound.h"

Sound::Sound()
{
	media_level = 0;
	call_level = 0;
	navi_level = 0;
	notification_level = 0;
}

Sound::~Sound()
{}

int Sound::get_media_level() {
	return media_level;
}
int Sound::get_call_level() {
	return call_level;
}

int Sound::get_navi_level() {
	return navi_level;
}

int Sound::get_notification_level() {
	return notification_level;
}

void Sound::set_media_level(int data) {
	this->media_level = data;
}

void Sound::set_call_level(int data) {
	this->call_level = data;
}

void Sound::set_navi_level(int data) {
	this->navi_level = data;
}

void Sound::set_notification_level(int data) {
	this->notification_level = data;
}

int checkNum()
{
	regex Sound_level("[0-9]+");
	string s_Sound_level = "";
	bool valid = true;
	do {
		getline(cin, s_Sound_level);
		if (!regex_match(s_Sound_level, Sound_level)) {
			cout << "Input value follow number!!!\n";
			cout << "enter again: ";
			valid = false;
		}
		else
		{
			valid = true;
		}
	} while (!valid);
	return stoi(s_Sound_level);
}

void Sound::nhapThongTin()
{
	cout << endl;
	cout << "-----NHAP CAC THONG TIN SOUND----- \n";
	cout << "NHAP MEDIA_LEVEL: ";
	this->media_level = checkNum();
	cout << "NHAP CALL_LEVEL: ";
	this->call_level = checkNum();
	cout << "NHAP NAVI_LEVEL: ";
	this->navi_level = checkNum();
	cout << "NHAP NOTIFICATION_LEVEL: ";
	this->notification_level = checkNum();
}

void Sound::xuatThongTin()
{
	cout << setw(15) << get_media_level() << setw(10) << get_call_level() << setw(10) << get_navi_level() << setw(10) << get_notification_level();
}

string Sound::toStringSound()
{
	stringstream stm;
	stm << "Sound: " << get_media_level() << "," << get_call_level() << "," << get_navi_level()<<"," << get_notification_level() << ";";
	return stm.str();
}

