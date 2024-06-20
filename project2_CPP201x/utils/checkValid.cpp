#include "checkValid.h"

int check_input_setting(int n)
{
	regex re_num("(\\+|-)?[0-9]+");
	string s = "";
	while (1) {
		string output = "";
		getline(cin, s);
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

// Check personalKey
int check_personalKey(const string& a_personalKey, List<Setting*>& listCar)
{
	bool exist = false;
	int m = -1;
	for (int i = 0; i < listCar.size(); i++)
	{
		if (a_personalKey == listCar.get(i)->getPersonalKey())
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
}

// Check input
int check_input(int n)
{
	regex re_num("^[0-9]+$");// format digit charactter
	string input;
	int NumberReturn = 0;
	while (1) {
		cout << "Enter your choice: ";
		getline(cin, input);
		if (regex_match(input, re_num) && stoi(input) < n && stoi(input) > 0)
		{
			NumberReturn = stoi(input);
			break;
		}
	}
	return NumberReturn;
}

//check yes or no follows y or n
char checkYorN() 
{
	string s;
	char a;
	bool isvalid = true;
	do {
		cin >> s;
		if ((s.length() > 1)) { //no entering more than 1 charater or numeric character
			isvalid = false;
			cout << "please only enter y/n: ";
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
			cout << "please only enter y/n: ";
		}
	} while (!isvalid);
	return a;
}