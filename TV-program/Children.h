#pragma once
#include "TVprogram.h"
class Children :
	public TVprogram
{
private:
	int minAge; // ������������ �������
	int maxAge; // ����������� �������
	types type;

public:
	Children(string name, int hours, int minutes, int minAge, int maxAge);
	~Children();
	Children(Children& obj);

	void setMinAge(int minAge);
	int getMinAge();
	void setMaxAge(int minAge);
	int getMaxAge();

	string toString() override;
	void showProgram() override;
	int getType() override;
};

