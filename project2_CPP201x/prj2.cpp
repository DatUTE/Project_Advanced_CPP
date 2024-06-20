#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <regex>
#include <memory>
#include "Car.h"
#include "CommonInfo.h"
#include "checkValid.h"
#include "List.h"

List<Setting*> listCar;
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

void SaveData();
void LoadData();

int menu();
int check_input(int n);
void sortList_name();
void sortList_mscn();
bool sortName(CommonInfo& a_string, CommonInfo& b_string);
bool sortNumber(CommonInfo& a_string, CommonInfo& b_string);

// show Menu and selection 
int menu() {
	system("clear");
	int selection = 0;
	cout << "--------------HELLO--------------\n";
	cout << "1. Input the setting information\n";
	cout << "2. Print the setting information\n";
	cout << "3. Exit\n";
	selection = check_input(4);
	switch (selection)
	{
	case 3:									// Exit 
		system("clear");
		cout << "SEE YOU LATER!!!\n";
		exit(0);
		break;
	case 1:									// Input info
		system("clear");
		NhapThongTinCaiDat();
		break;
	case 2:									// Output info
		system("clear");
		XuatThongTinCaiDat();
		break;
	}
	return selection;
}


// Input Infomation
void NhapThongTinCaiDat() {
	system("clear");
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
		system("clear");
		menu();
		break;
	}
	case 2: {
		cout << " \n--- Nhap thong tin Sound --- " << endl;
		NhapThongTinCaiDat_Sound();
		system("clear");
		menu();
		break;
	}
	case 3: {
		cout << " \n--- Nhap thong tin General --- " << endl;
		NhapThongTinCaiDat_General();
		system("clear");
		menu();
		break;
	}
	case 4: {
		system("clear");
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
	system("clear");
	char continues = 'n';
	do {
		Setting* tempCar = new Setting();
		cout << "---Input Displaying Setting---\n"
			<< "Car index: " << listCar.size() + 1 << endl;
		tempCar->nhapThongTin();	//enter personal information (name, email,...)
		if (listCar.size() > 0)
		{
			n = check_personalKey(tempCar->getPersonalKey(), listCar);	//check if userkey existed or not
			if (n == listCar.size()) {
				listCar.add(tempCar);
			}
			else {
				listCar.get(n)->copyInfo(tempCar);
			}
			listCar.get(n)->getDisplay()->nhapThongTin();	// call Sound object from Setting obj and access nhapThongTin_Display()
		}
		else
		{
			cout << "This is the first car\n";
			tempCar->getDisplay()->nhapThongTin();			// call Sound object from Setting obj and access nhapThongTin_Display()
			listCar.add(tempCar);
		}
		cout << "WILL YOU INPUT FOR CAR " << (listCar.size()) + 1 << " ? (y/n): ";

		continues = checkYorN();
		cout << endl;

	} while (continues == 'y');
	SaveData();
	system("clear");
	menu();

}

// Input Sound Information
void NhapThongTinCaiDat_Sound()
{
	shared_ptr<Sound> p_sound = make_shared<Sound>();
	char continues = 'n';
	do {
		Setting* tempCar = new Setting();
		cout << "---Input Sound Setting---\n"
			<< "Car index: " << listCar.size() + 1 << endl;
		tempCar->nhapThongTin();	//enter personal information (name, email,...), simalar to Sound setting
		int m;
		if (listCar.size() > 0) {
			m = check_personalKey(tempCar->getPersonalKey(), listCar);	//check if userkey existed or not
			if (m == listCar.size()) {
				listCar.add(tempCar);
			}
			else {
				listCar.get(m)->copyInfo(tempCar);
			}
			p_sound->nhapThongTin();
			listCar.get(m)->setSound(std::move(p_sound));
			// call Sound object from Setting obj and access nhapThongTin_Display()
		}
		else {
			cout << "This is the first car\n";
			p_sound->nhapThongTin();
			tempCar->setSound(std::move(p_sound));		// call Sound object from Setting obj and access nhapThongTin_Display()
			listCar.add(tempCar);
		}

		cout << "WILL YOU INPUT FOR CAR " << listCar.size() + 1 << " ? (y/n): ";
		continues = checkYorN();
		cout << endl;
	} while (continues == 'y');
	SaveData();
	system("clear");
	menu();
}

// Input General Information
void NhapThongTinCaiDat_General()
{
	int var;
	char continues = 'n';
	do {
		Setting* tempCar = new Setting();
		int n = 0;
		cout << "---INPUT GENERAL SETTING--- \n" << "Car Index: " << listCar.size() + 1 << endl;
		tempCar->nhapThongTin();						//enter personal information (name, email,...)
		if (listCar.size() > 0)
		{
			n = check_personalKey(tempCar->getPersonalKey(), listCar); //check if userkey existed or not
			if (n == listCar.size())
			{
				listCar.add(tempCar);
			}
			else
			{
				listCar.get(n)->copyInfo(tempCar);
			}
			//show list of timezones
			showTimeZone();
			cout << endl;
			int timeZone_count = check_input(timezoneList.size() + 1); //chose timezones by entering a number on the list
			listCar.get(n)->getGeneral()->set_timeZone(timezoneList[timeZone_count - 1].getNumber()); // set timezones acording to the number entered above

			// show language list and similar to timezone.....
			showLanguage();
			cout << endl;
			int language_count = check_input(languageList.size() + 1);
			listCar.get(n)->getGeneral()->set_language(languageList[language_count - 1].getName());
		}
		else
		{
			cout << "This is the first car\n";
			listCar.add(tempCar);

			showTimeZone();
			cout << endl;
			int timeZone_count = check_input(timezoneList.size() + 1); //chose timezones by entering a number on the list
			listCar.get(n)->getGeneral()->set_timeZone(timezoneList[timeZone_count - 1].getNumber()); // set timezones acording to the number entered above

			// show language list and similar to timezone.....
			showLanguage();
			cout << endl;
			int language_count = check_input(languageList.size() + 1);
			listCar.get(n)->getGeneral()->set_language(languageList[language_count - 1].getName());
		}
		cout << "WILL YOU INPUT FOR CAR:  " << listCar.size() + 1 << " ? (y/n): ";
		continues = checkYorN();
		system("clear");
		cout << endl;
	} while (continues == 'y');

	SaveData();
	system("clear");
	menu();
}
// Ouput Information
void XuatThongTinCaiDat() {
	system("clear");
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
		system("clear");
		menu();
		break;
	}
	case 2:
	{
		cout << " --- Xuat thong tin Sound --- " << endl;
		XuatThongTinCaiDat_Sound();
		system("clear");
		menu();
		break;
	}
	case 3:
	{
		cout << " --- Xuat thong tin General --- " << endl;
		XuatThongTinCaiDat_General();
		system("clear");
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
	system("clear");
	sortList_name();
	cout << "---Sound setting---\n";
	cout << setw(5) << "Car Name" << setw(10) << "Email" << setw(13) << "MSC" << setw(7) << "ODO" << setw(12) << "SEVICES" << setw(15) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify" << endl;
	for (int i = 0; i < listCar.size(); i++) {
		listCar.get(i)->xuatThongTin();					// output personal information
		listCar.get(i)->getSound()->xuatThongTin();		// output sound information
		cout << endl;
	}
	system("read -p 'Press Enter to continue...' var");
	menu();
}
// Ouput General Information
void XuatThongTinCaiDat_General() {
	system("clear");
	sortList_name();
	cout << "---General setting---\n";
	cout << setw(5) << "Car Name" << setw(10) << "Email" << setw(13) << "MSC" << setw(7) << "ODO" << setw(12) << "SEVICES" << setw(17) << "TimeZone" << setw(14) << "Language" << endl;
	for (int i = 0; i < listCar.size(); i++)
	{
		listCar.get(i)->xuatThongTin();					// output personal information
		listCar.get(i)->getGeneral()->xuatThongTin();	// output general information
		cout << endl;
	}

	system("read -p 'Press Enter to continue...' var");
}
// Ouput Display Information
void XuatThongTinCaiDat_Display() {
	system("clear");
	sortList_name();
	cout << "---Display setting---\n";
	cout << setw(5) << "Car Name" << setw(10) << "Email" << setw(13) << "MSC" << setw(7) << "ODO" << setw(12) << "SEVICES" << setw(15) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen" << endl;
	for (int i = 0; i < listCar.size(); i++)
	{
		listCar.get(i)->xuatThongTin();
		listCar.get(i)->getDisplay()->xuatThongTin();
		cout << endl;
	}
	system("read -p 'Press Enter to continue...' var");
}
// Ouput All Information
void XuatTatCaThongTinCaiDat() {
	int choose;
	do
	{
		system("clear");
		cout << "1. Sap xep theo ten " << endl;
		cout << "2. Sap xep theo mscn" << endl;
		cout << "3. Quay lai menu" << endl;
		cout << "4. Thoat " << endl;
		choose = check_input(5);
		switch (choose)
		{
		case 1:
		{
			system("clear");
			cout << "Sap xep danh sach theo carname !" << endl;
			sortList_name();		// sort data by name
			for (int i = 0; i < listCar.size(); i++)
			{
				cout << "--------------------------------" << endl;
				cout << "Chiec xe thu: " << i + 1 << endl;
				cout << setw(5) << "Car Name" << setw(10) << "Email" << setw(13) << "MCS" << setw(8) << "ODO" << setw(10) << "Service" << endl;
				listCar.get(i)->xuatThongTin();
				cout << endl;
				cout << setw(5) << "Display: " << setw(8) << "Ligh" << setw(10) << "Taplo" << setw(10) << "Screen" << endl;
				listCar.get(i)->getDisplay()->xuatThongTin();
				cout << endl;
				cout << setw(5) << "Sound: " << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Noti" << endl;
				listCar.get(i)->getSound()->xuatThongTin();
				cout << endl;
				cout << setw(5) << "General: " << setw(10) << "TimeZone" << setw(15) << "Language" << endl;
				listCar.get(i)->getGeneral()->xuatThongTin();
				cout << endl;
				cout << endl;
			}
			system("read -p 'Press Enter to continue...' var");
			break;
		}

		case 2:
		{
			system("clear");
			cout << "Sap xep theo ma so ca nhan ! " << endl;
			sortList_mscn();	// sort data by mscn
			for (int i = 0; i < listCar.size(); i++)
			{
				cout << "--------------------------------" << endl;
				cout << "Chiec xe thu: " << i + 1 << endl;
				cout << setw(5) << "Car Name" << setw(10) << "Email" << setw(13) << "MCS" << setw(8) << "ODO" << setw(10) << "Service" << endl;
				listCar.get(i)->xuatThongTin();
				cout << endl;
				cout << setw(5) << "Display: " << setw(8) << "Ligh" << setw(10) << "Taplo" << setw(10) << "Screen" << endl;
				listCar.get(i)->getDisplay()->xuatThongTin();
				cout << endl;
				cout << setw(5) << "Sound: " << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Noti" << endl;
				listCar.get(i)->getSound()->xuatThongTin();
				cout << endl;
				cout << setw(5) << "General: " << setw(10) << "TimeZone" << setw(15) << "Language" << endl;
				listCar.get(i)->getGeneral()->xuatThongTin();
				cout << endl;
				cout << endl;
			}
			system("read -p 'Press Enter to continue...' var");
			break;
			break;
		}
		case 3:
		{
			system("clear");
			menu();
			break;
		}
		case 4:
			cout << "SEE YOU LATER!" << endl;
			exit(0);
			break;
		}
		system("read -p 'Press Enter to continue...' var");
	} while (1);
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

// sort by name
void sortList_name()
{
	cout << "sort by name" << endl;

	for (int i = 0; i < listCar.size() - 1; i++)
	{

		for (int j = 0; j < listCar.size() - 1; j++) {
			if (listCar.get(j)->getCarName() > listCar.get(j + 1)->getCarName())
			{
				listCar.Swap(j, j + 1);
			}
		}
	}
}
//sort by mscn
void sortList_mscn()
{
	cout << "sort by mscn" << endl;

	for (int i = 0; i < listCar.size() - 1; i++)
	{

		for (int j = 0; j < listCar.size() - 1; j++) {
			if (listCar.get(j)->getPersonalKey() > listCar.get(j + 1)->getPersonalKey())
			{
				listCar.Swap(j, j + 1);
			}
		}
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
// this is used to write data into file
void SaveData() {
	ofstream file1("Setting.txt");
	try {
		if (file1.is_open()) {
			for (int i = 0; i < listCar.size(); i++) { //write all data of obj elements: personal info, general, sound,display into file
				file1 << "Common: " << listCar.get(i)->getCarName() << "," << listCar.get(i)->getEmail() << "," << listCar.get(i)->getPersonalKey() << "," << listCar.get(i)->getODO() << "," << listCar.get(i)->getServiceRemind() << " ; ";
				file1 << "General: " << listCar.get(i)->getGeneral()->get_timeZone() << " , " << listCar.get(i)->getGeneral()->get_language() << " ; ";
				file1 << "Sound: " << listCar.get(i)->getSound()->get_media_level() << "," << listCar.get(i)->getSound()->get_call_level() << "," << listCar.get(i)->getSound()->get_navi_level() << "," << listCar.get(i)->getSound()->get_notification_level() << " ; ";
				file1 << "Display: " << listCar.get(i)->getDisplay()->get_light_level() << "," << listCar.get(i)->getDisplay()->get_screen_light_level() << "," << listCar.get(i)->getDisplay()->get_taplo_light_level() << " ;" << endl;
			}
		}
		else {
			throw exception(); //throw out the warning
		}
	}
	catch (const exception& e) {
		cerr << "khong mo duoc file Setting.txt" << endl;
	}
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
				vector<string>PerInfo;
				vector<string>Sound;
				vector<string>Display;
				stringstream ss(s);
				int i = 0;
				while (ss.good() && i < 13) { //split a long sentence into single strings and assign them into an array
					ss >> arrS[i];
					i++;
				}
				PerInfo = explode(arrS[1], ','); //personal info is the 2nd element, then using exploe to erase ',' and add it into a vector
				temp->setCarName(PerInfo[0]);
				temp->setEmail(PerInfo[1]);
				temp->setPersonalKey(PerInfo[2]);
				temp->setODO(stoi(PerInfo[3]));
				temp->setServiceRemind(stoi(PerInfo[4]));
				temp->getGeneral()->set_timeZone(arrS[4]); //timezone is the 5th element of arrS
				temp->getGeneral()->set_language(arrS[6]); // langua is the 7th element of arrS
				Sound = explode(arrS[9], ','); // sound information is the 10th element
				temp->getSound()->set_media_level(stoi(Sound[0]));
				temp->getSound()->set_call_level(stoi(Sound[1]));
				temp->getSound()->set_navi_level(stoi(Sound[2]));
				temp->getSound()->set_notification_level(stoi(Sound[3]));
				Display = explode(arrS[12], ','); // display information is the 13th element
				temp->getDisplay()->set_light_level(stoi(Display[0]));
				temp->getDisplay()->set_screen_light_level(stoi(Display[1]));
				temp->getDisplay()->set_taplo_light_level(stoi(Display[2]));
				listCar.add(temp); // add it into the array elements_ of private of List
			}
		}
		else {
			throw -1;
		}
	}
	catch (int e) {
		cerr << "error code: " << e << endl;
	}
}
int main(int argc, char** argv)
{
	LoadData();
	downloadLanguage();
	downloadTimeZone();
	int choice = 0;
	choice = menu();
	system("read -p 'Press Enter to continue...' var");
	return 0;
}
