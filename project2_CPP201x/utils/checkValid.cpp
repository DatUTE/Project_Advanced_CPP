#include "checkValid.h"
int input_check(int n)
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