#pragma once
#include<iostream>
#include<string>
#include<stdlib.h>
#include"StringException.h"
#include"Time.h"
#include"Date.h"
using namespace std;

class TVprogram
{
protected:
	enum types {
		CHIL = 1,
		SHOW = 3,
		MOVI = 4,
		EDUC = 2
	};
	string name;	    //�������� ��������
	Time_ releaseTime; // ����� ������
	void coutReleaseTime(); // ����� �� ����� ������� ������ (������������ ������������ � showProgram)
	string toStringRT(); // ������������ ������ �� ������� ������ (������������ ������������ � toString)

public:

	void setName(string name);
	string getName();

	void setReleaseTime(int hours, int minutes);
	Time_ getReleaseTime();

	virtual string toString() = 0; // ������������ ������ �� �������
	virtual void showProgram() = 0; // ���������� � ���������
	virtual int getType() = 0;     // ��� �������������
};

