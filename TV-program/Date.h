#pragma once
#include <iostream>
using namespace std;

class Date
{
	int year;
	int month;
	int day;

	

public:
	//---------ÊÎÍÑÒÐÓÊÒÎÐÛ è ÄÅÑÒÐÓÊÒÎÐ---------
	Date(); // Ïî óìîë÷àíèþ  - òåêóùàÿ äàòà
	Date(int year, int month, int day); //Ñ ïàðàìåòðàìè - çàäàííàÿ äàòà
	Date(const Date& obj); //Êîïèðîâàíèÿ
	~Date();// Äåñòðóêòîð

	void showInfo();
	void sv(int y, int m, int d);

	bool isLeapYear(); //Ïðîâåðêà íà âèñîêîñíûé ãîä
	int monthDays(); //Êîëè÷åñòâî äíåé ïî ìåñÿöó
	void nextDate(); //Ñëåäóþùàÿ äàòà
	void prevDate(); //Ïðåäûäóùàÿ äàòà

	void setNowDate();

			//---------ÀÊÑÅÑÑÎÐÛ---------
	void setYear(int year);
	int getYear();
	void setMonth(int month);
	int getMonth();
	void setDay(int day);
	int getDay();

	bool valid(); //Ïðîâåðêà äàòû íà êîððåêòíîñòü
	
				  //--------- ÎÏÅÐÀÒÎÐÛ ÑÐÀÂÍÅÍÈß ---------
	bool operator == (const Date& obj);
	bool operator != (const Date& obj);
	bool operator > (const Date& obj);
	bool operator < (const Date& obj);
	bool operator >= (const Date& obj);
	bool operator <= (const Date& obj);

	//--------- ÎÏÅÐÀÒÎÐÛ ÏÐÈÑÂÎÅÍÈß ---------
	Date& operator = (const Date& obj);
	Date& operator += (int n);
	Date& operator -= (int n);

	//--------- ÀÐÈÔÌÅÒÈ×ÅÑÊÈÅ ÎÏÅÐÀÒÎÐÛ ---------
	Date operator + (int n);
	Date operator - (int n);
	int operator -(const Date & tmp);
	Date operator +(const Date & tmp);

	////incriment/decrement
	Date& operator ++();
	Date& operator ++(int a);
	Date& operator --();
	Date& operator --(int a);


	///friendship

	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
	friend ofstream& operator << (ofstream& fout, Date& d);
	friend ifstream& operator >> (ifstream& fin, Date& d);

};


