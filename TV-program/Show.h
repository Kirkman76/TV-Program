#pragma once
#include "TVprogram.h"
class Show :
	public TVprogram
{
private:
	string theme; // тема
	types type;


public:
	Show(string name, int hours, int minutes, string theme);
	~Show();
	Show(Show& obj);

	void setTheme(string theme);
	string getTheme();

	string toString() override;
	void showProgram() override;
	int getType() override;
};

