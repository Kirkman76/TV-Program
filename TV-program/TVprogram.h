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
	string name;	    //название передачи
	Time_ releaseTime; // время выхода
	void coutReleaseTime(); // вывод на экран времени выхода (используется наследниками в showProgram)
	string toStringRT(); // формирование строки из времени выхода (используется наследниками в toString)

public:

	void setName(string name);
	string getName();

	void setReleaseTime(int hours, int minutes);
	Time_ getReleaseTime();

	virtual string toString() = 0; // формирование строки из объекта
	virtual void showProgram() = 0; // информация о программе
	virtual int getType() = 0;     // тип телепрограммы
};

