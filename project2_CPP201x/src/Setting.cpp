#include "Setting.h"
#include "checkValid.h"
#include <regex>

Setting::Setting()
{
	m_general = make_shared<General>();
	m_sound = make_shared<Sound>();
	m_display = make_shared<Display>();
}
Setting::~Setting()
{

}
// ouput information setting
void Setting::xuatThongTin()
{
	cout << setw(5) << getCarName() << setw(18) << getEmail() << setw(10) << getPersonalKey() << setw(5) << getODO() << setw(10) << getServiceRemind();
}
// input information setting
void Setting::nhapThongTin()
{

	regex re_email("^([a-zA-Z0-9_\\.\\-]{3,})+\\@(([a-zA-Z0-9\\-]{3,})+\\.)+([a-zA-Z0-9]{3})+$");	// Email phai co dang emai@abc.xyz form
	regex re_perKey("^[0-9]{8}$");// ma so ca nhan phai du 8 so
	regex re_name("^([a-zA-Z]){2,20}$");
	string carName;
	string email;
	string personalKey;
	while (1)
	{
		cout << "Nhap Ten Xe: ";
		getline(cin, carName);
		setCarName(carName);
		cin.ignore(0);
		if (!regex_match(getCarName(),re_name))	// ten xe khong duoc la 1 chuoi rong or ki tu dac biet
		{
			cout << "Ten khong duoc la khoang trong hoac ki tu dac biet! " << endl;
		}
		else
		{
			break;
		}
	}
	while (1)
	{
		cout << "Nhap Email: ";
		getline(cin, email);
		setEmail(email);
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
		cin >> personalKey;
		setPersonalKey(personalKey);
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
	cin.ignore(1);
	cout << "Nhap ODO: ";
	setODO(check_input_setting(0));
	cout << "Nhap service_remind: ";
	setServiceRemind(check_input_setting(0));

}

void Setting::setGeneral(shared_ptr<General> p_general)
{
	m_general = p_general;
}

shared_ptr<General> Setting::getGeneral()
{
	return m_general;
}

void Setting::setSound(shared_ptr<Sound> p_sound)
{
	m_sound = p_sound;
}

shared_ptr<Sound> Setting::getSound()
{
	return m_sound;
}

void Setting::setDisplay(shared_ptr<Display> p_display)
{
	m_display = p_display;
}

shared_ptr<Display> Setting::getDisplay()
{
	return m_display;
}

void Setting::copyInfo(Setting* st)
{
	setCarName(st->getCarName());
	setEmail(st->getEmail());
	setODO(st->getODO());
	setPersonalKey(st->getPersonalKey());
	setServiceRemind(st->getServiceRemind());
}


