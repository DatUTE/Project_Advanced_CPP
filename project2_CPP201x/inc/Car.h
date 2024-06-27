#ifndef Car_H_
#define Car_H_

#include<iostream>
#include<string>
#include<fstream>
#include<regex>
using namespace std;

class Car
{
	string car_name;
	string personal_key; // Chuoi 8 ky tu so
	string email; // email format abc@xyz.com
	int odo;
	int service_remind;
public:
	Car();
	~Car();
	virtual void nhapThongTin() = 0;
	virtual void xuatThongTin() = 0;

	string getCarName();
	string getPersonalKey();
	int getODO();
	string getEmail();
	int getServiceRemind();
	void setCarName(const string& data);
	void setPersonalKey(const string& data);
	void setODO(int data);
	void setEmail(const string& data);
	void setServiceRemind(int data);

};
#endif /* Car_H_ */






