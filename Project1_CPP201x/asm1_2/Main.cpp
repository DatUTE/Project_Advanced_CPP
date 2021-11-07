#include <iostream>

#include <string>
#include "Car.h"
#include "Setting.h"
#include "CommonInfo.h"
#include <fstream>
#include <stdlib.h>
#include <regex>
#define cls system("cls")

Setting *listCar = new Setting[100];
Setting *tempCar = new Setting();
static int count_car = 0;

vector<CommonInfo> timezoneList;
vector<CommonInfo> languageList;

void NhapThongTinCaiDat();
void XuatThongTinCaiDat();

void XuatThongTinCaiDat_Sound();
void XuatThongTinCaiDat_General();
void XuatThongTinCaiDat_Display();
void XuatTatCaThongTinCaiDat();

void NhapThongTinCaiDat_Sound();
void NhapThongTinCaiDat_General();
void NhapThongTinCaiDat_Display();

void downloadTimeZone();
void downloadLanguage();
void showTimeZone();
void showLanguage();

int menu();
int check_input(int n);
bool sortName(CommonInfo& a_string, CommonInfo& b_string);
bool sortNumber(CommonInfo& a_string, CommonInfo& b_string);
// Check personalKey
int check_personalKey(string a_personalKey)
{
	bool exist = false;
	int m = -1;
	for (int i = 0; i < count_car; i++)
	{
		if (a_personalKey == listCar[i].getPersonalKey())
		{
			exist = true;
			m = i;
			break;
		}
	}
	if (exist)
	{
		cout << "Xe " << m + 1 << " Da Ton Tai, Thong Tin Se Bi Ghi De !";
		return m;
	}
	else
	{
		cout << "Chiec Xe Moi " << count_car + 1;
		return count_car;
	}
}
// Check input
int check_input(int n)
{
	regex s_num("[0-9]+");
	string s_checkInput = "";
	int a = 0;
	do
	{
		cout << "Nhap Lua Chon Cua Ban: ";
		cin >> s_checkInput;
		if(regex_match(s_checkInput,s_num))
		{
			if ((stoi(s_checkInput) <= n))
			{
				a = stoi(s_checkInput);
			}
		}
		cin.ignore(1);
	} while (!regex_match(s_checkInput, s_num));
	return a;
}

//check yes or no follows y or n
char checkYorN() {
	while (1) {
		string inputYoN = "";
		getline(cin, inputYoN);
		if (inputYoN.length() == 1) {
			if (inputYoN[0] == 'y' || inputYoN[0] == 'n' || inputYoN[0] == 'N' || inputYoN[0] == 'Y') {
				return inputYoN[0];
			}
			else {
				cout << "Please enter yes or no (y/n)!!!\n";
				cout << "enter again: ";
			}
		}
		else {
			cout << "Please enter yes or no (y/n)!!!\n";
			cout << "enter again: ";
		}
	}
}
// check valua input in menu
bool check1(int y)
{
	for (int i = 1; i <= 3; i++)
	{
		if (y == i) { return true; }
	}
	return false;
}
// show Menu and selection 
int menu()
{
	system("cls");
	int choice;
	cout << "Nhap Lua Chon" << endl;
	cout << "1. Nhap Thong Tin" << endl;
	cout << "2. Xuat Thong Tin" << endl;
	cout << "3. Thoat Chuong Trinh" << endl;
	choice = check_input(3);
	do
	{
		while (!check1(choice))
		{
			cout << "SAI CU PHAP, MOI BAN NHAP LAI: ";
			choice = check_input(3);
			cout << "Nhap Lua Chon" << endl;
			cout << "1. Nhap Thong Tin" << endl;
			cout << "2. Xuat Thong Tin" << endl;
			cout << "3. Thoat Chuong Trinh" << endl;

		}
		cls;
		switch (choice)
		{
		case 1:
		{
			cls;
			cout << "Nhap Thong Tin Cai Dat " << endl;
			NhapThongTinCaiDat();
			break;
		}
		case 2:
		{
			cls;
			cout << "Xuat Thong Tin Cai Dat " << endl;
			XuatThongTinCaiDat();
		}
		case 3:
		{
			cls;
			exit(0);
			break;
			return 0;
		}
		}
	}
	while (choice != 4);
}
	

// Input Infomation
void NhapThongTinCaiDat() {
	cls;
	int choice;
	cout << "-------Nhap Thong Tin Cai Dat-------" << endl;
	cout << "1. Nhap thong tin Display" << endl;
	cout << "2. Nhap thong tin Sound" << endl;
	cout << "3. Nhap thong tin General" << endl;
	cout << "4. Quay Lai Menu" << endl;
	choice = check_input(5);
	switch (choice) {
	case 1: {
		cout << " \n--- Nhap thong tin Display --- " << endl;
		NhapThongTinCaiDat_Display();
		cls;
		menu();
		break;
	}
	case 2: {
		cout << " \n--- Nhap thong tin Sound --- " << endl;
		NhapThongTinCaiDat_Sound();
		cls;
		menu();
		break;
	}
	case 3: {
		cout << " \n--- Nhap thong tin General --- " << endl;
		NhapThongTinCaiDat_General();
		cls;
		menu();
		break;
	}
	case 4: {
		cls;
		menu();
		break;
	}
	}
}

// Input Display Information
void NhapThongTinCaiDat_Display()
{
	char continues = 'n';
	do {
		cout << "Nhap Thong Tin Display Xe So:" << count_car +1 << endl;
		tempCar->nhapThongTin(); //enter personal information (name, email,...), simalar to Sound setting
		int n = check_personalKey(tempCar->getPersonalKey());
		listCar[n].copyInfo(tempCar);
		listCar[n].getDisplay()->nhapThongTin();		// enter display information
		if (n == count_car) {
			count_car++;
		}
		cout << "Ban Se Tiep Tuc Xe So: " << count_car + 1 << " ? (y/n): ";
		continues = checkYorN();
		cls;
		cout << endl;
	} while (continues == 'y');
	menu();
}

// Input Sound Information
void NhapThongTinCaiDat_Sound()
{
	char continues = 'n';
	do
	{
		int m = 0;
		cout << " NHAP THONG TIN SOUND, XE SO " << count_car + 1  << endl;
		tempCar->nhapThongTin();									// enter personal information
		m = check_personalKey(tempCar->getPersonalKey()); 
		listCar[m].copyInfo(tempCar);
		listCar[m].getSound()->nhapThongTin();						// enter sound information
		if (m == count_car)
		{
			count_car += 1;
		}
		cout << "TIEP TUC XE SO " << count_car + 1 << " ? (y/n): ";
		continues = checkYorN();
		cls;
		cout << endl;
	} while (continues == 'y');
}

// Input General Information
void NhapThongTinCaiDat_General()
{
	char continues = 'n';
	do {
		cout << "Nhap Thong Tin Generel Xe So: " << count_car +1 << endl;
		tempCar->nhapThongTin();						//enter personal information (name, email,...)
		int n = check_personalKey(tempCar->getPersonalKey()); //check if userkey existed or not
		listCar[n].copyInfo(tempCar);
		cout << endl;

		//show list of timezones
		showTimeZone();	
		cout << endl;
		int timeZone_count = check_input(timezoneList.size()); //chose timezones by entering a number on the list
		listCar[n].getGeneral()->set_timeZone(timezoneList[timeZone_count - 1].getNumber()); // set timezones acording to the number entered above

		// show language list and similar to timezone.....
		showLanguage();								
		cout << endl;
		int language_count = check_input(languageList.size());
		listCar[n].getGeneral()->set_language(languageList[language_count - 1].getName());
		if (n == count_car) {
			count_car++;
		}
		cout << "Ban Se Tiep Tuc Xe So: " << count_car + 1 << " ? (y/n): ";
		continues = checkYorN();
		cls;
		cout << endl;
	} while (continues == 'y');
	menu();
}
// Ouput Information
void XuatThongTinCaiDat() {
	cls;
	int choice;
	cout << "-------Xuat Thong Tin Cai Dat-------" << endl;
	cout << "1. Xuat thong tin Display" << endl;
	cout << "2. Xuat thong tin Sound" << endl;
	cout << "3. Xuat thong tin General" << endl;
	cout << "4. Xuat tat ca thong tin" << endl;
	cout << "5. Quay Lai Menu !" << endl;
	choice = check_input(6);
	switch (choice)
	{
	case 1:
	{
		cout << " --- Xuat thong tin Display --- " << endl;
		XuatThongTinCaiDat_Display();
		cls;
		menu();
		break;
	}
	case 2:
	{
		cout << " --- Xuat thong tin Sound --- " << endl;
		XuatThongTinCaiDat_Sound();
		cls;
		menu();
		break;
	}
	case 3:
	{
		cout << " --- Xuat thong tin General --- " << endl;
		XuatThongTinCaiDat_General();
		cls;
		menu();
		break;
	}
	case 4:
	{
		cout << " --- Xuat tat ca thong tin --- " << endl;
		XuatTatCaThongTinCaiDat();
		menu();
		break;
	}
	case 5:
	{
		menu();
		break;
	}
	}
}

const vector<string> explode(const string& s, const char& c)
{
	string buff{ "" };
	vector<string> v;

	for (auto n : s)
	{
		if (n != c)
			buff += n;
		else if (n == c && buff != "")
		{
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
		v.push_back(buff);

	return v;
}

// Ouput Sound Information
void XuatThongTinCaiDat_Sound() {
	system("cls");
	cout << "---Sound setting---\n";
	cout << setw(5) << "Car Name" << setw(10) << "Email" << setw(13) << "MSC" << setw(7) << "ODO" << setw(12) << "SEVICES" << setw(15) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify" << endl;
	for (int i = 0; i < count_car; i++) {
		listCar[i].xuatThongTin();					// output personal information
		listCar[i].getSound()->xuatThongTin();		// output sound information
		cout << endl;
	}
	system("pause");
}
// Ouput General Information
void XuatThongTinCaiDat_General() {
	system("cls");
	cout << "---General setting---\n";
	cout << setw(5) << "Car Name" << setw(10) << "Email" << setw(13) << "MSC" << setw(7) << "ODO" << setw(12) << "SEVICES" << setw(15) << "TimeZone" << setw(15) << "Language" << endl;
	for (int i = 0; i < count_car; i++)
	{
		listCar[i].xuatThongTin();					// output personal information
		listCar[i].getGeneral()->xuatThongTin();	// output general information
		cout << endl;
	}
	system("pause");
}
// Ouput Display Information
void XuatThongTinCaiDat_Display() {
	cls;
	cout << "---Display setting---\n";
	cout << setw(5) << "Car Name" << setw(10) << "Email" << setw(13) << "MSC" << setw(7) << "ODO" << setw(12) << "SEVICES" << setw(15) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen" << endl;
	for (int i = 0; i < count_car; i++)
	{
		listCar[i].xuatThongTin();
		listCar[i].getDisplay()->xuatThongTin();
		cout << endl;
	}
	system("pause");
}
// Ouput All Information
void XuatTatCaThongTinCaiDat() {
	cls;
	for (int i = 0; i < count_car; i++)
	{
		cout << "--------------------------------" << endl;
		cout << "Chiec xe thu: " << i + 1 << endl;
		cout << setw(5) << "Car Name" << setw(10) << "Email" << setw(13) << "MCS" << setw(8) << "ODO" << setw(10) << "Service" << endl;
		listCar[i].xuatThongTin();
		cout << endl;
		cout << setw(5) << "Display: " <<  setw(8) << "Ligh" << setw(10) << "Taplo" << setw(10) << "Screen" << endl;
		listCar[i].getDisplay()->xuatThongTin();
		cout << endl;
		cout << setw(5) << "Sound: " << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Noti" << endl;
		listCar[i].getSound()->xuatThongTin();
		cout << endl;
		cout << setw(5) << "General: " << setw(10) << "TimeZone" << setw(15) << "Language" << endl;
		listCar[i].getGeneral()->xuatThongTin();
		cout << endl;
		cout << endl;
	}
	system("pause");
}

// Input Information General

void showTimeZone()
{
	sort(timezoneList.begin(), timezoneList.end(),sortName);
	for (int i = 0; i < timezoneList.size(); i++) 
	{
		if (i < 10)
		{
			cout << i + 1 << "  : " << timezoneList[i].getNumber() << "-" << timezoneList[i].getName() << endl;
		}
		else
		{
			cout << i + 1 << " : " << timezoneList[i].getNumber() << "-" << timezoneList[i].getName() << endl;
		}
	}
}

void showLanguage()
{
	sort(languageList.begin(), languageList.end(), sortName);
	for (int i = 0; i < languageList.size(); i++) 
	{
		if (i < 10)
		{
			cout << i + 1 << "  :" << languageList[i].getName() << endl;
		}
		else
		{
			cout << i + 1 << " :" << languageList[i].getName() << endl;
		}
	}
}

//download into vector timezone

void downloadTimeZone() {
	string h;
	CommonInfo com;
	vector <string> Temp_CommonInfo;
	ifstream f("timezones.txt");
	if (f.is_open()) {
		while (getline(f, h)) {
			Temp_CommonInfo = explode(h, '/');
			com.setNumber(Temp_CommonInfo[0]);
			com.setName(Temp_CommonInfo[1]);
			timezoneList.push_back(com);
		}
	}
	else {
		cout << "unable to open file timezones";
	}
	vector <string> names;
	for (int i = 0; i < timezoneList.size(); i++) {
		names.push_back(timezoneList[i].getName());
	}
}

//download into vector language

void downloadLanguage() {
	string s;
	CommonInfo com;
	vector<string> Temp_CommonInfo;
	ifstream f("languages.txt");
	if (f.is_open()) {
		while (getline(f, s)) {
			Temp_CommonInfo = explode(s, '/');
			com.setNumber(Temp_CommonInfo[0]);
			com.setName(Temp_CommonInfo[1]);
			languageList.push_back(com);
		}
		f.close();
	}
	else {
		cout << "unable to open file languages";
	}
	vector<string> names;
	for (int i = 0; i < languageList.size(); i++) {
		names.push_back(languageList[i].getName());
	}
}


//sort by name timezone or language

bool sortName(CommonInfo& a_string, CommonInfo& b_string)
{
	return (a_string.getName() < b_string.getName());
}
//sort by name timezone or language

bool sortNumber(CommonInfo& a_string, CommonInfo& b_string)
{
	return (a_string.getNumber() < b_string.getNumber());
}
int main(int argc, char** argv) 
{

	downloadLanguage();
	downloadTimeZone();
	int choice = 0;
	choice = menu();
	system("pause");
	delete[] listCar;
	delete tempCar;
	return 0;
}
