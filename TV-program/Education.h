#pragma once
#include "TVprogram.h"
class Education :
	public TVprogram
{
private:
	string science; //какая область науки
	types type;

public:
	Education(string name, int hours, int minutes, string science);
	~Education();
	Education(Education& obj);

	void setScience(string science);
	string getScience();

	string toString() override;
	void showProgram() override;
	int getType() override;

};

