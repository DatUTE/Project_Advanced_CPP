
#include "Car.h"

Car::Car()
{
	car_name = "";
	personal_key = ""; 	// Chuoi 8 ky tu so
	email = "";			// email format abc@xyz.com
	odo = 0;
	service_remind = 0;
}

Car::~Car()
{
}
string Car::getCarName() {
	return this->car_name;
}
string Car::getEmail() {
	return this->email;
}
string Car::getPersonalKey() {
	return this->personal_key;
}

int Car::getODO() {
	return this->odo;
}

int Car::getServiceRemind() {
	return this->service_remind;
}
void Car::setCarName(string data) {
	this->car_name = data;
}
void Car::setPersonalKey(string data) {
	this->personal_key = data;
}
void Car::setEmail(string data) {
	this->email = data;
}
void Car::setODO(int data) {
	this->odo = data;
}
void Car::setServiceRemind(int data) {
	this->service_remind = data;
}



