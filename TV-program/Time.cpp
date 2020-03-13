#include "Time.h"
#include<ctime>
#include<iostream>
//#include<conio.h>
#include<Windows.h>
#include "Time.h"
using namespace std;

Time_::Time_()
{
	time_t t = time(NULL); // текущее врем€
	tm tick;
	// заполнение полей структуры
	localtime_s(&tick, &t); // распределение значений по пол€м

	hour = tick.tm_hour;
	minutes = tick.tm_min + 1;
	seconds = tick.tm_sec;

	format = new char[4];
	strcpy_s(format, 4, "utc");
}

Time_::Time_(int hour, int minutes, int seconds, const char* format)
{
	this->hour = hour;
	this->minutes = minutes;
	this->seconds = seconds;
	this->format = new char[strlen(format) + 1];
	strcpy_s(this->format, strlen(format) + 1, format);
}

Time_::Time_(const Time_& obj)
{
	this->seconds = obj.seconds;
	this->minutes = obj.minutes;
	this->hour = obj.hour;
	this->format = new char[strlen(obj.format) + 1];
	strcpy_s(this->format, strlen(obj.format) + 1, obj.format);
}

Time_::~Time_()
{
	delete[] format;
}

void Time_::setHour(int hour)
{
	if (hour > -1 && hour < 24) {
		this->hour = hour;
	}
	else {
		this->hour = 0;
	}
}

int Time_::getHour()
{
	return hour;
}

void Time_::setMinutes(int minutes)
{
	if (minutes > -1 && minutes < 61) {
		this->minutes = minutes;
	}
	else {
		this->minutes = 0;
	}
}

int Time_::getMinutes()
{
	return minutes;
}

void Time_::setSeconds(int seconds)
{
	if (seconds > -1 && seconds < 61) {
		this->seconds = seconds;
	}
	else {
		this->seconds = 0;
	}
}

int Time_::getSeconds()
{
	return seconds;
}

void Time_::changeFormat()
{
	if (valid()) {

		if (!_stricmp(format, "utc") && hour > 12 && hour < 24) {
			delete[] format;
			format = new char[3];
			strcpy_s(format, 3, "pm");

			hour -= 12;
		}
		else if (!_stricmp(format, "utc") && hour < 12 && hour > 0) {
			delete[] format;
			format = new char[3];
			strcpy_s(format, 3, "am");
		}
		else if (!_stricmp(format, "utc") && hour == 0) {
			delete[] format;
			format = new char[3];
			strcpy_s(format, 3, "am");

			hour = 12;
		}
		else if (!_stricmp(format, "utc") && hour == 12) {
			delete[] format;
			format = new char[3];
			strcpy_s(format, 3, "pm");

			hour = 12;
		}
		else if (!_stricmp(format, "utc") && hour == 24) {
			delete[] format;
			format = new char[3];
			strcpy_s(format, 3, "am");

			hour = 12;
		}
		else if (!_stricmp(format, "pm") && hour == 12) {
			delete[] format;
			format = new char[4];
			strcpy_s(format, 4, "utc");

			hour = 12;
		}
		else if (!_stricmp(format, "am") && hour == 12) {
			delete[] format;
			format = new char[4];
			strcpy_s(format, 4, "utc");

			hour = 24;
		}
		else if (!_stricmp(format, "pm")) {
			delete[] format;
			format = new char[4];
			strcpy_s(format, 4, "utc");

			hour += 12;
		}
		else {
			delete[] format;
			format = new char[4];
			strcpy_s(format, 4, "utc");
		}
	}
	else {
		cout << "Imvalid time format!\n";
	}
}

const char* Time_::getFormat()
{
	return format;
}

bool Time_::valid()
{
	if ((!_stricmp(format, "am") || !_stricmp(format, "pm")) && seconds >= 0 && seconds < 60 && minutes >= 0 && minutes < 60 && hour > 0 && hour <= 12) {
		return true;
	}
	else if (!_stricmp(format, "utc")  && seconds >= 0 && seconds < 60 && minutes >= 0 && minutes < 60 && hour >= 0 && hour < 24) {
		return true;
	}

	return false;
}

void Time_::tickTime()
{
	if (valid()) {


		int hou;

		if (!_stricmp(format, "utc")) { // установка перехода 24/12 - часовый формат
			hou = 23;
		}
		else {
			hou = 11;
		}

		bool go = false; // чтобы корректно работало если запускать счЄтчик с 12.xx am/pm

		for (;;) {

			showTime();
			Sleep(1000);
			seconds += 1;

			if (seconds > 59) {
				seconds = 0;
				minutes += 1;
			}
			if (minutes > 59) {
				minutes = 0;
				hour += 1;
				go = true;
			}
			if (hour > hou && go) { // при 24ч режиме сработает только переход 23.59-00.00
				if (hour == 12) { // смена am/pm при переходе 12.00

					if (!_stricmp(format, "am")) {
						strcpy_s(format, 3, "pm");
					}
					else {
						strcpy_s(format, 3, "am");
					}

					hou = 12; // измен€етс€ дл€ того, чтобы сначала произошЄл переход am/pm при 12.00, а в следующий час переход 12.59-01.00
					go = false;

				}
				else if (hour == 13) { //переход 12.59-01.00
					hour = 1;
					go = false;
					hou = 11;
				}
				else { // переход 23.59-00.00
					hour = 0;
					go = false;
				}

			}
			system("cls");
		}
	}
	else {
		cout << "Imvalid time format!\n";
	}
}

void Time_::showTime()
{
	cout << format << " " << hour / 10 << hour % 10 << ":" << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10 << endl;
}

bool Time_::operator==(const Time_& obj)
{
	if (!_stricmp(this->format, obj.format) && this->minutes == obj.minutes && this->seconds == obj.seconds && this->hour == obj.hour) {
		return true;
	}
	if (!_stricmp(this->format, "utc") && !_stricmp(obj.format, "am") && this->minutes == obj.minutes && this->seconds == obj.seconds && (this->hour == obj.hour || (this->hour == 0 && obj.hour == 12)) && this->hour != 12) {
		return true;
	}
	if (!_stricmp(this->format, "utc") && !_stricmp(obj.format, "pm") && this->minutes == obj.minutes && this->seconds == obj.seconds && (this->hour == obj.hour + 12 || (this->hour == 12 && obj.hour == 12))) {
		return true;
	}
	if (!_stricmp(this->format, "am") && !_stricmp(obj.format, "utc") && this->minutes == obj.minutes && this->seconds == obj.seconds && (this->hour == obj.hour || (this->hour == 12 && obj.hour == 0)) && this->hour != 12) {
		return true;
	}
	if (!_stricmp(this->format, "pm") && !_stricmp(obj.format, "utc") && this->minutes == obj.minutes && this->seconds == obj.seconds && (this->hour + 12 == obj.hour || (this->hour == 12 && obj.hour == 12))) {
		return true;
	}
	return false;
}

bool Time_::operator!=(const Time_& obj)
{
	return !(*this == obj);
}

bool Time_::operator>(const Time_& obj)
{
	if (!_stricmp(this->format, obj.format)) {
		if (this->hour > obj.hour) {
			return true;
		}
		else if (this->hour == obj.hour) {
			if (this->minutes > obj.minutes) {
				return true;
			}
			else if (this->minutes == obj.minutes) {
				if (this->seconds > obj.seconds) {
					return true;
				}
				else return false;
			}
			return false;
		}
		return false;
	}

	if (!_stricmp(this->format, "am") && !_stricmp(obj.format, "pm")) {
		return false;
	}

	if (!_stricmp(this->format, "pm") && !_stricmp(obj.format, "am")) {
		return true;
	}

	if (!_stricmp(this->format, "utc") && !_stricmp(obj.format, "am")) {
		if (this->hour > obj.hour) {
			return true;
		}
		else if (this->hour == obj.hour || (this->hour == 0 && obj.hour == 12) ) {
			if (this->minutes > obj.minutes) {
				return true;
			}
			else if (this->minutes == obj.minutes) {
				if (this->seconds > obj.seconds) {
					return true;
				}
				else return false;
			}
			return false;
		}
		return false;
	}

	if (!_stricmp(this->format, "utc") && !_stricmp(obj.format, "pm") && this->hour >= 12 && this->hour < 24) {
		if ((this->hour - 12 > obj.hour) || (this->hour > 12 && obj.hour == 12)) {
			return true;
		}
		else if ((this->hour == 12 && obj.hour == 12) || (this->hour - 12 == obj.hour)) {
			if (this->minutes > obj.minutes) {
				return true;
			}
			else if (this->minutes == obj.minutes) {
				if (this->seconds > obj.seconds) {
					return true;
				}
				else return false;
			}
			return false;
		}
		return false;
	}

	if (!_stricmp(this->format, "am") && !_stricmp(obj.format, "utc")) {
		if (this->hour > obj.hour) {
			return true;
		}
		else if (this->hour == obj.hour || (this->hour == 12 && obj.hour == 0)) {
			if (this->minutes > obj.minutes) {
				return true;
			}
			else if (this->minutes == obj.minutes) {
				if (this->seconds > obj.seconds) {
					return true;
				}
				else return false;
			}
			return false;
		}
		return false;
	}

	if (!_stricmp(this->format, "pm") && !_stricmp(obj.format, "utc") && obj.hour >= 12 && obj.hour < 24) {
		if ((this->hour > obj.hour) || (this->hour == 12 && obj.hour < 12)) {
			return true;
		}
		else if ((this->hour == 12 && obj.hour == 12) || (this->hour == obj.hour - 12)) {
			if (this->minutes > obj.minutes) {
				return true;
			}
			else if (this->minutes == obj.minutes) {
				if (this->seconds > obj.seconds) {
					return true;
				}
				else return false;
			}
			return false;
		}
		return false;
	}
	else return true;

	return false;
}

bool Time_::operator<(const Time_& obj)
{
	return (!(*this > obj) && !(*this == obj));
}

bool Time_::operator>=(const Time_& obj)
{
	return ((*this > obj) || (*this == obj));
}

bool Time_::operator<=(const Time_& obj)
{
	return ((!(*this > obj) && !(*this == obj)) || (*this == obj));
}

Time_& Time_::operator=(const Time_& obj)
{
	// TODO: insert return statement here
	if (this->format != NULL) {
		delete[] format;
	}
	this->format = new char[strlen(obj.format) + 1];
	strcpy_s(this->format, strlen(obj.format) + 1, obj.format);
	this->hour = obj.hour;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;
	return *this;
}

Time_& Time_::operator+=(int n)
{
	// TODO: insert return statement here
	if (valid()) {


		int hou;

		if (!_stricmp(format, "utc")) { // установка перехода 24/12 - часовый формат
			hou = 23;
		}
		else {
			hou = 11;
		}

		bool go = false; // чтобы корректно работало если запускать счЄтчик с 12.xx am/pm

		for (;n!=0;n--) {

			seconds += 1;

			if (seconds > 59) {
				seconds = 0;
				minutes += 1;
			}
			if (minutes > 59) {
				minutes = 0;
				hour += 1;
				go = true;
			}
			if (hour > hou && go) { // при 24ч режиме сработает только переход 23.59-00.00
				if (hour == 12) { // смена am/pm при переходе 12.00

					if (!_stricmp(format, "am")) {
						strcpy_s(format, 3, "pm");
					}
					else {
						strcpy_s(format, 3, "am");
					}

					hou = 12; // измен€етс€ дл€ того, чтобы сначала произошЄл переход am/pm при 12.00, а в следующий час переход 12.59-01.00
					go = false;

				}
				else if (hour == 13) { //переход 12.59-01.00
					hour = 1;
					go = false;
					hou = 11;
				}
				else { // переход 23.59-00.00
					hour = 0;
					go = false;
				}

			}
		}
	}
	else {
		cout << "Imvalid time format!\n";
	}
	return *this;
}

Time_& Time_::operator-=(int n)
{
	// TODO: insert return statement here
	bool chForm = false;
	if (valid()) {

		if (_stricmp(format, "utc") != 0) { //
			changeFormat();
			chForm = true;
		}

		bool go = false; // чтобы корректно работало если запускать счЄтчик с 12.xx am/pm

		for (;n!=0;n--) {

			seconds -= 1;

			if (seconds < 0) {
				seconds = 59;
				minutes -= 1;
				go = true;
			}
			if (minutes < 0 && go) {
				minutes = 59;
				hour -= 1;
				go = true;
			}
			if ((hour < 0) && go) { 			
					hour = 23;
			}
			go = false;
		}
	}
	else {
		cout << "Imvalid time format!\n";
	}
	if (chForm) {
		changeFormat();
	}
	return *this;
}

Time_ Time_::operator+(int n)
{
	Time_ tmp = *this;
	tmp += n;
	return tmp;
}

Time_ Time_::operator-(int n)
{
	Time_ tmp = *this;
	tmp -= n;
	return tmp;
}

Time_& Time_::operator--()
{
	// TODO: insert return statement here
	*this -= 1;

	return *this;
}

Time_& Time_::operator--(int n)
{
	// TODO: insert return statement here
	Time_ tmp = *this;
	*this -= 1;

	return tmp;
}

Time_& Time_::operator++()
{
	// TODO: insert return statement here

	*this += 1;

	return *this;
}

Time_& Time_::operator++(int n)
{
	// TODO: insert return statement here
	Time_ tmp = *this;
	*this -= 1;

	return tmp;
}

ostream& operator<<(ostream& out, const Time_& obj)
{
	// TODO: insert return statement here
	out << obj.format << " " << obj.hour / 10 << obj.hour % 10 << ":" << obj.minutes / 10 << obj.minutes % 10 << ":" << obj.seconds / 10 << obj.seconds % 10 << endl;;
	return out;
}

istream& operator>>(istream& in, Time_& obj)
{
	// TODO: insert return statement here
	int select = 0;
	cout << "„асы:\n";
	in >> select;
	obj.setHour(select);
	cout << "ћинуты\n";
	in >> select;
	obj.setMinutes(select);
	cout << "—екунды\n";
	in >> select;
	obj.setSeconds(select);

	return in;
}
