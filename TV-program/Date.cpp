#include "Date.h"
#include <fstream>
#include <ctime>
#include <iostream>
using namespace std;



ostream& operator<<(ostream& out, const Date& d)
{
	// TODO: insert return statement here
	out << d.day << "/" << d.month << "/" << d.year;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	// TODO: insert return statement here
	cout << "¬ведите день: "; in >> d.day;
	cout << "¬ведите мес€ц: "; in >> d.month;
	cout << "¬ведите год: "; in >> d.year;
	return in;
}

ofstream& operator<<(ofstream& fout, Date& d)
{
	// TODO: вставьте здесь оператор return
	fout <<  " " << d.day << " " << d.month << " " << d.year;
	return fout;
}

ifstream& operator>>(ifstream& fin, Date& d)
{
	// TODO: вставьте здесь оператор return
	fin >> d.day >> d.month >> d.year;
	return fin;
}





Date::Date()
{
	struct tm *tim = new tm;
	time_t tt = time(NULL);
	localtime_s(tim, &tt);

	this->day = tim->tm_mday;
	this->month = tim->tm_mon + 1;
	this->year = tim->tm_year + 1900;
}

Date::Date(int year, int month, int day)
{
	if (month > 12 || month < 1 || day>31 || day < 1)
	{
		cout << "Ќекорректные значени€!";

		struct tm *tim = new tm;
		time_t tt = time(NULL);
		localtime_s(tim, &tt);

		this->day = tim->tm_mday;
		this->month = tim->tm_mon + 1;
		this->year = tim->tm_year + 1900;
		return;
	}

	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(const Date & obj)
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
}


Date::~Date()
{
}

void Date::showInfo()
{
	cout << this->day << "/" << this->month << "/" << this->year << endl;
}

void Date::sv(int y, int m, int d)
{
	this->day = d;
	this->month = m;
	this->year = y;
}

bool Date::isLeapYear()
{
	int y = this->year;

	if (y % 100 == 0 && y % 400 == 0)return true;
	else if (y % 100 == 0 && y % 400 != 0)return false;
	else if (y % 4 == 0)return true;
	else return false;
}

int Date::monthDays()
{
	switch (this->month)
	{
	case 1:

		return 31;
		break;

	case 2:
		if (this->isLeapYear())return 29;
		else return 28;

	case 3:
		return 31;
		break;
	case 4:
		return 30;
		break;
	case 5:
		return 31;
		break;
	case 6:
		return 30;
		break;
	case 7:
		return 31;
		break;

	case 8:
		return 31;
		break;
	case 9:
		return 30;
		break;
	case 10:
		return 31;
		break;
	case 11:
		return 30;
		break;
	case 12:
		return 31;
		break;
	}

	return 0;
}

void Date::nextDate()
{
	if (this->day == 31 && this->month == 12) {
		this->day = 1;
		this->month = 12;
		this->year++;
	}
	else if (this->day == monthDays())
	{
		this->month++;
		this->day = 1;
	}
	else this->day++;

}

void Date::prevDate()
{
	if (this->day == 1 && this->month == 1)
	{
		this->month = 12;
		this->day = 31;
		this->year--;
	}
	else if (this->day == 1)
	{
		this->month--;
		this->day = monthDays();
	}
	else this->day--;

}

void Date::setNowDate()
{
	struct tm *tim = new tm;
	time_t tt = time(NULL);
	localtime_s(tim, &tt);

	this->day = tim->tm_mday;
	this->month = tim->tm_mon + 1;
	this->year = tim->tm_year + 1900;
}

void Date::setYear(int year)
{
	this->year = year;
}

int Date::getYear()
{
	return this->year;
}

void Date::setMonth(int month)
{
	if (month > 0 && month < 13)this->month = month;
}

int Date::getMonth()
{
	return this->month;
}

void Date::setDay(int day)
{
	if (day > 0 && day < 32)this->day = day;
}


int Date::getDay()
{
	return this->day;
}

bool Date::valid()
{
	if (this->day < 32 && this->day >0 && this->month < 13 && this->month>0)return true;
	else return false;
}

bool Date::operator==(const Date & obj)
{
	if (this->day == obj.day && this->month == obj.month && this->day == obj.day)return true;
	else return false;
}

bool Date::operator!=(const Date & obj)
{
	return !(*this == obj);
}

bool Date::operator>(const Date & obj)
{
	if (this->year > obj.year) return true;
	else if (this->year == obj.year && this->month > obj.month)return true;
	else if (this->year == obj.year && this->month == obj.month && this->day > obj.day)return true;
	else return false;

	return false;
}

bool Date::operator<(const Date & obj)
{
	return !(*this>obj) && *this != obj;
}

bool Date::operator>=(const Date & obj)
{
	if (this->year >= obj.year) return true;
	else if (this->year == obj.year && this->month >= obj.month)return true;
	else if (this->year == obj.year && this->month == obj.month && this->day >= obj.day)return true;
	else return false;

	return false;
}

bool Date::operator<=(const Date & obj)
{
	if (this->year <= obj.year) return true;
	else if (this->year == obj.year && this->month <= obj.month)return true;
	else if (this->year == obj.year && this->month == obj.month && this->day <= obj.day)return true;
	else return false;

	return false;
}

Date & Date::operator=(const Date & obj)
{
	// TODO: insert return statement here
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
	return *this;
}

Date & Date::operator+=(int n)
{
	// TODO: insert return statement here
	for (int i = 0; i < n; i++)
	{
		this->nextDate();
	}
	return *this;
}

Date & Date::operator-=(int n)
{
	// TODO: insert return statement here
	for (int i = 0; i < n; i++)
	{
		this->prevDate();
	}
	return *this;
}

Date Date::operator+(int n)
{
	Date tmp;
	tmp = *this;
	tmp += n;

	return tmp;
}

Date Date::operator-(int n)
{
	Date tmp;
	tmp = *this;
	tmp -= n;

	return tmp;
}

int Date::operator-(const Date & tmp)
{
	int am = 0;
	Date tmp1 = tmp;
	while (*this > tmp1)
	{
		tmp1.nextDate();
		am++;
	}
	
	while (*this < tmp1)
	{
		tmp1.prevDate();
		am--;
	}
	if (*this == tmp)return 0;
	return am;
}

Date Date::operator+(const Date & tmp)
{
	Date tmp1;
	int y = this->year + tmp.year;
	int m = this->month + tmp.month;
	int d = this->day + tmp.day;

	while (m > 12)
	{
		m -= 12;
		y++;
	}
	tmp1.sv(y, m, 20);

	while (d > tmp1.monthDays())
	{
		d -= tmp1.monthDays();
		m++;
	}
	tmp1.sv(y, m, d);

	while (m > 12)
	{
		m -= 12;
		y++;
	}
	tmp1.sv(y, m, 20);

	return tmp1;
}


Date & Date::operator++()
{
	// TODO: insert return statement here
	this->nextDate();
	return *this;
}

Date & Date::operator++(int a)
{
	// TODO: insert return statement here
	Date tmp = *this;
	this->nextDate();
	return tmp;
}

Date & Date::operator--()
{
	// TODO: insert return statement 
	this->prevDate();
	return *this;
}

Date & Date::operator--(int a)
{
	// TODO: insert return statement here
	Date tmp = *this;
	this->prevDate();
	return tmp;
}

