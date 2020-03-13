#pragma once
#include<iostream>
using namespace std;
class Time_

{
private:
	int hour;
	int minutes;
	int seconds;
	char* format;// am/pm (12-hours), utc (24-hours)

public:
	Time_(); // Current local time
	Time_(int hour, int minutes, int seconds, const char* format = "utc");
	Time_(const Time_& obj);
	~Time_();

	void setHour(int hour);
	int getHour();
	void setMinutes(int minutes);
	int getMinutes();
	void setSeconds(int seconds);
	int getSeconds();
	void changeFormat(); // !!! to update time by the new format
	const char* getFormat();

	bool valid(); //time check
	void tickTime(); //every tick add one second
	void showTime(); //show time by the format

	////--------- Comparison operators ---------
	bool operator == (const Time_& obj);
	bool operator != (const Time_& obj);
	bool operator > (const Time_& obj);
	bool operator < (const Time_& obj);
	bool operator >= (const Time_& obj);
	bool operator <= (const Time_& obj);

	////--------- Assignment operators ---------
	Time_& operator = (const Time_& obj);
	Time_& operator += (int n);
	Time_& operator -= (int n);

	////--------- Arithmetic operators ---------
	Time_ operator + (int n);
	Time_ operator - (int n);

	////----------Инкремент и декремент---------
	Time_& operator -- ();
	Time_& operator -- (int n);
	Time_& operator ++ ();
	Time_& operator ++ (int n);

	////----------Операторы ввода-вывода--------
	friend ostream& operator << (ostream& out, const Time_& obj);
	friend istream& operator >> (istream& in, Time_& obj);

};
