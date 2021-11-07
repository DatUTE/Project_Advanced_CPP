#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <regex>
#include <algorithm>
#include "Car.h"
#include "Setting.h"
#include "CommonInfo.h"
#include "BST.h"
#define cls system("cls")

BST listCar;

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

void LoadData();

int menu();
int check_input(int n);
fstream f("Setting.txt");
//sort language and timezone
bool sortName(CommonInfo& a_string, CommonInfo& b_string);
bool sortNumber(CommonInfo& a_string, CommonInfo& b_string);
// sort personal
bool sortName_per(Setting* a_string, Setting* b_string);
bool sortNumber_per(Setting* a_string, Setting* b_string);

// Check personalKey
/*int check_personalKey(string a_personalKey)
{
	bool exist = false;
	int m = -1;
	for (int i = 0; i < listCar.size(); i++)
	{
		if (listCar[i]->searchNodeInKey(a_personalKey))
		{
			exist = true;
			m = i;
			break;
		}
	}
	if (exist)
	{
		cout << "Xe " << m + 1 << " Da Ton Tai, Thong Tin Se Bi Ghi De !" << endl;
		return m;
	}
	else
	{
		cout << "Chiec Xe Moi " << listCar.size() + 1 << endl; ;
		return (listCar.size());
	}
}*/
// Check input
int check_input(int number)
{
	regex re_num("^[0-9]+$");// format digit charactter
	string input;
	int NumberReturn = 0;
	while (1) {
		cout << "Enter your choice: ";
		getline(cin, input);
		cin.ignore(0);
		if (regex_match(input, re_num) && stoi(input) < number && stoi(input) > 0)
		{
			NumberReturn = stoi(input);
			break;
		}
	}
	return NumberReturn;
}
//check yes or no follows y or n
char checkYorN() { //function to if check input is yes or no
	string s;
	char a;
	bool isvalid = true;
	do {
		getline(cin, s);
		if ((s.length() > 1)) { //no entering more than 1 charater or numeric character
			isvalid = false;
			continue;
		}
		else {
			isvalid = true;
		}
		a = s[0];
		if ((a == 'Y') || (a == 'y')) { //convert uppercase in to lowercase
			a = 'y';
		}
		else if ((a == 'n') || (a == 'N')) {
			a = 'n';
		}
		else {
			isvalid = false;
		}
	} while (!isvalid);
	return a;
}
string EnterKey() {
	regex re_personal("^[0-9]{8}$");// format 8 digits;
	string s;
	//cin >> s;
	while (1) {
		try {
			cout << "Enter personal key: ";		//enter user key and show warnig if input does not foollow 8 digits
			cin >> s;
			if (!regex_match(s, re_personal)) {
				throw "Input a value follows 8 digits!!!\n";
			}
			else if (listCar.searchNodeInKey(s) == NULL) {
				throw "This personal key does not exist\n";
			}
			else {
				break;
			}
		}
		catch (const char* err) {
			cout << err;
			cout << "Enter again: ";
		}
	}
	return s;
}
string EnterName() {
	string s = "";
	while (1) {
		cin.ignore(0);
		try {
			cout << "Enter car name: ";
			getline(cin, s);
			if (s.empty()) {		//do not let name empty
				throw "Input a value not null!!!\n";
			}
			else if (listCar.searchNodeInName(s).empty()) {
				throw "This name does not exist\n";
			}
			else {
				break;
			}
		}
		catch (const char* err) {
			cout << err;
			cout << "Enter again:...\n";
		}
	}
	return s;
}

bool mycomp(string a, string b) {	// funtion returns true if a,b is in alphabetically order
	return a < b;
}
vector<string> alphabaticallySort(vector<string> a) {	//sort elements of vector in alphabetically order
	sort(a.begin(), a.end(), mycomp);
	return a;
}
void swapObj(CommonInfo& obj1, CommonInfo& obj2) {	// swap 2 CommInfo objs
	CommonInfo temp_obj;
	temp_obj = obj1;
	obj1 = obj2;
	obj2 = temp_obj;
}
// show Menu and selection 
int menu() {
	system("cls");
	int choice = 0;
	cout << "--------------HELLO--------------\n";
	cout << "1. Input the setting information\n";
	cout << "2. Print the setting information\n";
	cout << "3. Exit\n";
	choice = check_input(4);
	switch (choice)
	{
	case 3:									// Exit 
		system("cls");
		cout << "SEE YOU LATER!!!\n";
		exit(0);
		break;
	case 1:									// Input info
		system("cls");
		NhapThongTinCaiDat();
		break;
	case 2:									// Output info
		system("cls");
		XuatThongTinCaiDat();
		break;
	}
	return choice;
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
	default:
	{
		exit(0);
		break;
	}
	}
}

// Input Display Information
void NhapThongTinCaiDat_Display()
{
	int n;
	cls;
	char continues = 'n';
	do {
		Setting* tempCar = new Setting();
		cout << "---Input Displaying Setting---\n"
			<< "Car index: " << listCar.sizeTree() + 1 << endl;
		tempCar->nhapThongTin();	//enter personal information (name, email,...)
		string n = tempCar->getPersonalKey();	//check if userkey existed or not
		if (listCar.sizeTree() > 0)
		{
			if ( listCar.searchNodeInKey(n) != NULL) {
				cout << "This car " << listCar.sizeTree() +1 << " already existed, data will be overitten\n"; 
				listCar.searchNodeInKey(n)->data->copyInfo(tempCar);
				listCar.searchNodeInKey(n)->data->getDisplay()->nhapThongTin();
			}
			else {
				cout << "This car " << listCar.sizeTree() + 1 << " data will be append to your list \n";
				tempCar->getDisplay()->nhapThongTin();
				listCar.InsertNode(tempCar);
			}
		}
		else
		{
			cout << "This is the first car\n";
			tempCar->getDisplay()->nhapThongTin();			// call Sound object from Setting obj and access nhapThongTin_Display()
			listCar.InsertNode(tempCar);
		}
		listCar.SaveDataOfNodes();
		cout << "WILL YOU INPUT FOR CAR " << listCar.sizeTree() + 1 << " ? (y/n): ";

		continues = checkYorN();
		cout << endl;
	} while (continues == 'y');
	system("cls");
	menu();

}

// Input Sound Information
void NhapThongTinCaiDat_Sound()
{
	char continues = 'n';
	do {
		Setting* tempCar = new Setting();
		cout << "---Input Sound Setting---\n"
			<< "Car index: " << listCar.sizeTree() + 1 << endl;
		tempCar->nhapThongTin();	//enter personal information (name, email,...), simalar to Sound setting
		string m = tempCar->getPersonalKey();	//check if userkey existed or not
		if (listCar.sizeTree() > 0) {

			if (listCar.searchNodeInKey(m) != NULL) {
				cout << "This car " << listCar.sizeTree() + 1 << " already existed, data will be overitten\n";
				listCar.searchNodeInKey(m)->data->copyInfo(tempCar);
				listCar.searchNodeInKey(m)->data->getSound()->nhapThongTin();
			}
			else {
				cout << "this car " << listCar.sizeTree() + 1 << " data will be append to your list \n";
				tempCar->getSound()->nhapThongTin();
				listCar.InsertNode(tempCar);
			}
		}
		else {
			cout << "This is the first car\n";
			tempCar->getSound()->nhapThongTin();			// call Sound object from Setting obj and access nhapThongTin_Display()
			listCar.InsertNode(tempCar);
		}
		listCar.SaveDataOfNodes();
		cout << "WILL YOU INPUT FOR CAR " << listCar.sizeTree() + 1 << " ? (y/n): ";
		continues = checkYorN();
		cout << endl;
	} while (continues == 'y');
	
	system("cls");
	menu();
}

void NhapThongTinCaiDat_General()	//General setting 
{
	char continues = 'n';
	do {
		Setting* tempCar = new Setting;
		cout << "---Input General Setting---\n"
			<< "Car index: " << listCar.sizeTree() + 1 << endl;
		tempCar->nhapThongTin();	//enter personal information (name, email,...)
		int n;
		if (listCar.sizeTree() + 1 > 0) {
			if (listCar.searchNodeInKey(tempCar->getPersonalKey()) != NULL) {
				cout << "This car " << listCar.sizeTree() + 1 << " already existed, data will be overitten\n";
				listCar.searchNodeInKey(tempCar->getPersonalKey())->data->copyInfo(tempCar);

				showTimeZone();		//show list of timezones
				int timezone_count = check_input(timezoneList.size() +1);			//chose timezones by entering a number on the list
				listCar.searchNodeInKey(tempCar->getPersonalKey())->data->getGeneral()->set_timeZone(timezoneList[timezone_count - 1].getNumber());	// set timezones acording to the number entered above
				
				showLanguage();		// show language list and similar to timezone.....
				int language_count = check_input(languageList.size() + 1);
				listCar.searchNodeInKey(tempCar->getPersonalKey())->data->getGeneral()->set_language(languageList[language_count - 1].getName());
			}
			else {
				cout << "This car " << listCar.sizeTree() + 1 << " data will be appended to your list\n";
				showTimeZone();		
				int timezone_count = check_input(timezoneList.size()+1);						
				tempCar->getGeneral()->set_timeZone(timezoneList[timezone_count - 1].getNumber());	
				
				showLanguage();				
				int language_count = check_input(languageList.size()+1);
				tempCar->getGeneral()->set_language(languageList[language_count - 1].getName());
				listCar.InsertNode(tempCar);
			}
		}
		else {
			cout << "This is the first car\n";
			showTimeZone();		
			int timezone_count = check_input(timezoneList.size()+1);						
			tempCar->getGeneral()->set_timeZone(timezoneList[timezone_count - 1].getNumber());	

			showLanguage();				
			int language_count = check_input(languageList.size()+1);
			tempCar->getGeneral()->set_language(languageList[language_count - 1].getName());
			listCar.InsertNode(tempCar);
		}
		listCar.SaveDataOfNodes();
		cout << "WILL YOU INPUT FOR CAR " << listCar.sizeTree() + 1 << " ? (y/n): ";
		continues = checkYorN();
		cout << endl;
	} while (continues == 'y');
	cls;
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
	if (listCar.sizeTree() > 0)
	{
		char n = 'n';
		do
		{
			cout << "---Sound setting---\n";
			string s = EnterKey();
			cout << setw(10) << "Car Name" << setw(10) << "Email" << setw(13) << "MSC" << setw(7) << "ODO" << setw(12) << "SEVICES" << setw(15) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify" << endl;
			listCar.searchNodeInKey(s)->data->xuatThongTin();
			listCar.searchNodeInKey(s)->data->getSound()->xuatThongTin();
			cout << "\nWILL YOU WANNA DISPLAY ANOTHER CAR ? (y/n): ";	// ask if user wanna display other cars or not	
			n = checkYorN();
			cout << endl;

		} while (n == 'y');
	}
	system("pause");
	menu();
}
// Ouput General Information
void XuatThongTinCaiDat_General() {
	cls;
	if (listCar.sizeTree() > 0)
	{
		char n = 'n';
		do
		{
			cout << "---Sound General---\n";
			string s = EnterKey();
			cout  << setw(10) << "Car Name" << setw(10) << "Email" << setw(13) << "MSC" <<setw(7) << "ODO" << setw(12) << "SERVICE"<< setw(17) << "Language" << setw(15) << "Timezone"<<endl;
			listCar.searchNodeInKey(s)->data->xuatThongTin();
			listCar.searchNodeInKey(s)->data->getGeneral()->xuatThongTin();
			cout << "\nWILL YOU WANNA DISPLAY ANOTHER CAR ? (y/n): ";	// ask if user wanna display other cars or not	
			n = checkYorN();
			cout << endl;

		} while (n == 'y');
	}

	system("pause");
}
// Ouput Display Information
void XuatThongTinCaiDat_Display() {
	cls;
	if (listCar.sizeTree() > 0)
	{
		char n = 'n';
		do
		{
			cout << "---Sound Display---\n";
			string s = EnterKey();
			cout << setw(10) << "Car Name" << setw(10) << "Email" << setw(13) << "MSC" << setw(7) << "ODO" << setw(12) << "SERVICE"
				 << setw(15) << "Light" << setw(10) << "Screen " << setw(10) << "Taplo " << endl;
			listCar.searchNodeInKey(s)->data->xuatThongTin();
			listCar.searchNodeInKey(s)->data->getDisplay()->xuatThongTin();
			cout << "\nWILL YOU WANNA DISPLAY ANOTHER CAR ? (y/n): ";	// ask if user wanna display other cars or not	
			n = checkYorN();
			cout << endl;

		} while (n == 'y');
	}
	system("pause");
}
// Ouput All Information
void XuatTatCaThongTinCaiDat() 
{
	cls;
	if (listCar.sizeTree() > 0)
	{
		cls;
		cout << "1. Nhap ten de xuat thong tin " << endl;
		cout << "2. Nhap MSCN de xuat thong tin " << endl;
		cout << "3. Xuat thong tin tat ca user " << endl;
		cout << "4. Quay ve " << endl;
		int choose = check_input(5);
		string s = "";
		switch (choose)
		{
		case 1:
		{
			cls;
			char n = 'n';
			do
			{
				system("cls");
				cout << "Get data by car name\n";
				s = EnterName();
				cout << setw(10) << "TEN CHU XE" << setw(10) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(12) << "SEVICES" 
					<< setw(15) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen"
					<< setw(15) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify"
					<< setw(17) << "TimeZone" << setw(15) << "Language" << endl;

				for (int i = 0; i < listCar.searchNodeInName(s).size(); i++) {
					listCar.searchNodeInName(s)[i]->data->xuatThongTin();
					listCar.searchNodeInName(s)[i]->data->getDisplay()->xuatThongTin();
					listCar.searchNodeInName(s)[i]->data->getSound()->xuatThongTin();
					listCar.searchNodeInName(s)[i]->data->getGeneral()->xuatThongTin();
					cout << endl;
				}
				system("pause");
				break;
			} while (n == 'y');
			XuatTatCaThongTinCaiDat();
			break;
		}
		case 2:
		{
			cls;
			char n = 'n';
			do {

				cout << "xuat du lieu nhap theo mscn ! " << endl;
				s = EnterKey();
				cout << "--------------------------------" << endl;
				cout << setw(10) << "Car Name" << setw(10) << "Email" << setw(13) << "MCS" << setw(8) << "ODO" << setw(10) << "Service" << endl;
				listCar.searchNodeInKey(s)->data->xuatThongTin();
				cout << endl;
				cout << setw(5) << "Display: " << setw(8) << "Ligh" << setw(10) << "Taplo" << setw(10) << "Screen" << endl;
				listCar.searchNodeInKey(s)->data->getDisplay()->xuatThongTin();
				cout << endl;
				cout << setw(5) << "Sound: " << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Noti" << endl;
				listCar.searchNodeInKey(s)->data->getSound()->xuatThongTin();
				cout << endl;
				cout << setw(5) << "General: " << setw(10) << "TimeZone" << setw(15) << "Language" << endl;
				listCar.searchNodeInKey(s)->data->getGeneral()->xuatThongTin();
				cout << endl;
				cout << "\nWILL YOU WANNA NEXT CAR  ? (y/n): ";	// ask if user wanna display other cars or not	
				n = checkYorN();
				system("pause");
			} while (n == 'y');

			XuatTatCaThongTinCaiDat();
			break;
		}
		case 3:
		{
			cls;
			cout << "Xuat tat ca thong tin user " << endl;
			cout << "print by name" << endl;
			cout << setw(8) << "CarName" << setw(12) << "Email" << setw(13) << "MSC" << setw(7) << "ODO" << setw(11) << "SEVICES"
				<< setw(15) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen"
				<< setw(15) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify"
				<< setw(17) << "TimeZone" << setw(15) << "Language" << endl;
			listCar.inorder_print(TYPE_ALL);
			system("pause");
			XuatTatCaThongTinCaiDat();
			break;
		}
		case 4:
		{
			XuatThongTinCaiDat();
			break;
		}
		default:
		{
			break;
		}
		system("pause");
		} while (1);
	}
	else
	{
		cout << "data empty !!!" << endl;
		system("pause");
		menu();
	}
}

void showTimeZone()
{
	//sort(timezoneList.begin(), timezoneList.end(), sortName);
	for (int i = 0; i < timezoneList.size(); i++)
	{
		if (i < 9)
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
		if (i < 9)
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
	vector <string> temp_commoninfo;
	ifstream f("timezones.txt");
	try {
		if (f.is_open()) {
			while (getline(f, h)) {
				temp_commoninfo = explode(h, '/');
				com.setNumber(temp_commoninfo[0]);
				com.setName(temp_commoninfo[1]);
				timezoneList.push_back(com);
			}
			f.close();
		}

		else {
			throw exception(); //throw out the warning

		}
	}
	catch (const exception& e) {
		ofstream file1("timezones_backup.txt");
		if (file1.is_open()) {
			file1 << "(GMT-12:00) /  International Date Line West\n" << "(GMT-11:00) /  Midway Island, Samoa\n" << "(GMT-10:00) /  Hawaii\n" << "(GMT-09:00) /  Alaska\n" << "(GMT-08:00) /  Tijuana, Baja California\n" << "(GMT-07:00) /  Chihuahua, La Paz, Mazatlan - New\n" << "(GMT-06:00) /  Guadalajara, Mexico City, Monterrey - New\n" << "(GMT-05:00) /  Eastern Time (US and Canada)\n" << "(GMT-04:00) /  Atlantic Time (Canada)\n" << "(GMT-03:30) /  Newfoundland\n" <<
				"(GMT-02:00) /  Mid-Atlantic\n" << "(GMT-01:00) /  Azores\n" << "(GMT-00:00) /  Monrovia, Reykjavik\n" << "(GMT+01:00) /  Belgrade, Bratislava, Budapest, Ljubljana, Prague\n" << "(GMT+02:00) /  Minsk\n" << "(GMT+03:00) /  Moscow, St. Petersburg, Volgograd\n" << "(GMT+04:00) /  Abu Dhabi, Muscat\n" << "(GMT+04:30) /  Kabul\n" << "(GMT+05:00) /  Tashkent\n" << "(GMT+05:30) /  Chennai, Kolkata, Mumbai, New Delhi\n" << "(GMT+05:45) /  Kathmandu\n" <<
				"(GMT+06:00) /  Astana, Dhaka\n" << "(GMT+06:30) /  Yangon (Rangoon)\n" << "(GMT+07:00) /  Bangkok, Hanoi, Jakarta\n" <<
				"(GMT+08:00) /  Beijing, Chongqing, Hong Kong, Urumqi\n" << "(GMT+08:00) /  Irkutsk, Ulaanbaatar\n" << "(GMT+09:00) /  Seoul\n" << "(GMT+09:30) /  Adelaide\n" << "(GMT+10:00) /  Canberra, Melbourne, Sydney\n" << "(GMT+11:00) /  Magadan, Solomon Islands, New Caledonia\n" << "(GMT+12:00) /  Fiji, Kamchatka, Marshall Is.\n" << "(GMT+13:00) /  Nuku'alofa\n";
		}
		file1.close();
		string s;
		CommonInfo com2;
		vector <string> temp_commoninfo2;
		ifstream f2("timezones_backup.txt");
		if (f2.is_open()) {
			while (getline(f2, s)) {
				temp_commoninfo2 = explode(s, '/');
				com2.setNumber(temp_commoninfo2[0]);
				com2.setName(temp_commoninfo2[1]);
				timezoneList.push_back(com2);
			}
			f2.close();
		}
	}
}
//download into vector language

void downloadLanguage() {
	string s;
	CommonInfo com;
	vector<string> Temp_CommonInfo;
	ifstream f("languages.txt");
	try
	{
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
			throw exception();
		}
		/*vector<string> names;
		for (int i = 0; i < languageList.size(); i++) {
			names.push_back(languageList[i].getName());
		}*/
	}

	catch (const std::exception&)
	{
		ofstream file1("languages_backup.txt");
		if (file1.is_open())
		{
			file1 << "1 / Mandarin (entire branch)" << "\n2 / Spanish" << "\n3 / English" << "\n4 / Hindi" << "\n5 / Arabic" << "\n6 / Portuguese"
				<< "\n7 / Bengali" << "\n8 / Russian" << "\n9 / Japanese" << "\n10 / Punjabi" << "\n11 / German" << "\n12 / Javanese"
				<< "\n13 / Wu (inc. Shanghainese)" << "\n14 / Malay (inc. Indonesian and Malaysian)" << "\n15 / Telugu" << "\n16 / Vietnamese" << "\n17 / Korean" << "\n18 / French"
				<< "\n19 / Marathi" << "\n20 / Tamil" << "\n21 / Urdu" << "\n22 / Turkish" << "\n23 / Italian" << "\n24 / Yue (inc. Cantonese)"
				<< "\n25 / Thai" << "\n26 / Gujarati" << "\n27 / Jin" << "\n28 / Southern Min" << "\n29 / Persian" << "\n30 / Polish";
		}
		file1.close();
		string s;
		CommonInfo com;
		vector<string> Temp_CommonInfo;
		ifstream f("languages_backup.txt");
		if (f.is_open())
		{
			while (getline(f, s)) {
				Temp_CommonInfo = explode(s, '/');
				com.setNumber(Temp_CommonInfo[0]);
				com.setName(Temp_CommonInfo[1]);
				languageList.push_back(com);
			}
			f.close();
		}
	}
}

//sort by name personal
bool sortName_per(Setting* a_string, Setting* b_string)
{
	return (a_string->getCarName() < b_string->getCarName());
}

//sort by name personal
bool sortNumber_per(Setting* a_string, Setting* b_string)
{
	return (a_string->getPersonalKey() < b_string->getPersonalKey());
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

//read data from file.txt
void LoadData() {
	string s;
	ifstream file1("Setting.txt");
	string arrS[13];
	try {
		if (file1.is_open()) {
			while (getline(file1, s)) {
				Setting* temp = new Setting;
				vector<string>vect_s;
				vect_s = explode(s, ';');
				vector<string> vect_common = explode(vect_s[0], ':');
				vector<string>vect_gen = explode(vect_s[1], ':');
				vector<string>vect_sou = explode(vect_s[2], ':');
				vector<string>vect_disp = explode(vect_s[3], ':');
				vector<string>sub_common = explode(vect_common[1], ',');
				vector<string>sub_gen = explode(vect_gen[2], ',');
				vector<string>sub_sou = explode(vect_sou[1], ',');
				vector<string>sub_disp = explode(vect_disp[1], ',');
				temp->setCarName(sub_common[0]);
				temp->setEmail(sub_common[1]);
				temp->setPersonalKey(sub_common[2]);
				temp->setODO(stoi(sub_common[3]));
				temp->setServiceRemind(stoi(sub_common[4]));
				temp->getGeneral()->set_timeZone(vect_gen[1] + ":" + sub_gen[0]);
				temp->getGeneral()->set_language(sub_gen[1]);
				temp->getSound()->set_media_level(stoi(sub_sou[0]));
				temp->getSound()->set_call_level(stoi(sub_sou[1]));
				temp->getSound()->set_navi_level(stoi(sub_sou[2]));
				temp->getSound()->set_notification_level(stoi(sub_sou[3]));
				temp->getDisplay()->set_light_level(stoi(sub_disp[0]));
				temp->getDisplay()->set_screen_light_level(stoi(sub_disp[1]));
				temp->getDisplay()->set_taplo_light_level(stoi(sub_disp[2]));
				listCar.InsertNode(temp);		// add it into the array elements_ of private of List
			}
		}
		else {
			throw "Unable to open file to read Setting.txt";
		}
	}
	catch (const char& e) {
		cerr << e << endl;
	}
}
int main(int argc, char** argv)
{
	LoadData();
	downloadLanguage();
	downloadTimeZone();
	int choice = 0;
	choice = menu();
	system("pause");
	return 0;
}
