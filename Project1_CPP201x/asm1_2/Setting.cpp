#include "Setting.h"
#include<regex>

int input_check(int n);
Setting::Setting()
{
	general = new General();
	sound = new Sound();
	display = new Display();
}
Setting::~Setting()
{
	if (general != nullptr) {
		delete general;
	}
	if (sound != nullptr) {
		delete sound;
	}
	if (display != nullptr) {
		delete display;
	}
}
// ouput information setting
void Setting::xuatThongTin()
{
	cout << setw(5) << getCarName() << setw(18) << getEmail() << setw(10) << getPersonalKey() << setw(5) << getODO() << setw(10) << getServiceRemind();
}
// input information setting
void Setting::nhapThongTin()
{
	
	regex re_email("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");// Email phai co dang emai@abc.xyz form
	regex re_perKey("^[0-9]{8}$");// ma so ca nhan phai du 8 so
	string a;
	while (1)
	{
		cout << "Nhap Ten Xe: ";
		getline(cin, a);
		setCarName(a);
		if (getCarName().empty())	// ten xe khong duoc la 1 chuoi rong
		{
			cout << "Gia Tri Nhap Vao Khong Duoc Trong";
		}
		else
		{
			break;
		}
	}
	while (1)
	{
		cout << "Nhap Email: ";
		getline(cin, a);
		setEmail(a);
		cin.ignore(0);
		if (!regex_match(getEmail(), re_email)) // kiem tra dieu kien email 
		{
			cout << "Email Nhap Vao Phai Theo Cu Phap email@abc.xyz";
		}
		else
		{
			break;
		}
	}
	while (1)
	{
		cout << "Nhap Ma So Ca Nhan: ";
		getline(cin, a);
		setPersonalKey(a);
		if (!regex_match(getPersonalKey(), re_perKey))	// kiem tra dieu kien mscn
		{
			cout << "Ma So Nhap Vao Phai Du 8 So";
		}
		else
		{
			{
				break;
			}
		}
	}
	cin.ignore(0);
	cout << "Nhap ODO: ";
	setODO(input_check(0));
	cout << "Nhap service_remind: ";
	setServiceRemind(input_check(0));

}

void Setting::setGeneral(General *gen)
{
	general = gen;
}
General* Setting::getGeneral()
{
	return general;
}
void Setting::setSound(Sound *sou)
{
	sound = sou;
}
Sound* Setting::getSound()
{
	return sound;
}
void Setting::setDisplay(Display *disp)
{
	display = disp;
}
Display *Setting::getDisplay()
{
	return display;
}
int input_check(int n)
{
	regex re_num("(\\+|-)?[0-9]+");
	string s = "";
	ofstream outFile;
	outFile.open("Setting.txt", ios::out);
	while (1) {
		string output = "";
		getline(cin, s);
		outFile << s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				continue;
			}
			else {
				output += s[i];
			}
		}
		if (!regex_match(output, re_num)) {
			cout << "Input value follow number!!!\n";
			cout << "enter again: ";
		}
		else {
			n = stoi(output);
			if (n < 0) {
				cout << "Input value greater than 0!!!\n";
				cout << "enter again: ";
			}
			else {
				return n;
			}
		}

	}
}
void Setting::copyInfo(Setting* st)
{
	setCarName(st->getCarName());
	setEmail(st->getEmail());
	setODO(st->getODO());
	setPersonalKey(st->getPersonalKey());
	setServiceRemind(st->getServiceRemind());
}

