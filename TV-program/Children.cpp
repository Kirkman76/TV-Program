#include "Children.h"



Children::Children(string name, int hours, int minutes, int minAge, int maxAge)
{
	try {
		setName(name);
		setReleaseTime(hours, minutes);
		setMinAge(minAge);
		setMaxAge(maxAge);
		type = CHIL; // ДЕТСКАЯ ПЕРЕДАЧА
	}
	catch (StringException& ex) {
		cout << ex.message();
	}
}


Children::~Children()
{
}

Children::Children(Children& obj)
{
	this->name = obj.name;
	this->releaseTime = obj.releaseTime;
	this->minAge = obj.minAge;
	this->maxAge = obj.maxAge;
	this->type = obj.type;
}

void Children::setMinAge(int minAge)
{
	try
	{
		if (minAge < 0 || minAge > 160) {
			throw exception("Неверно введён возраст!\n");
		}
		this->minAge = minAge;
	}
	catch (const exception& ex)
	{
		cout << ex.what();
	}
}

int Children::getMinAge()
{
	return minAge;
}

void Children::setMaxAge(int maxAge)
{
	try
	{
		if (maxAge < 0 || maxAge > 160) {
			throw exception("Неверно введён возраст!\n");
		}
		this->maxAge = maxAge;
	}
	catch (const exception& ex)
	{
		cout << ex.what();
	}
}

int Children::getMaxAge()
{
	return maxAge;
}

string Children::toString()
{
	return toStringRT() + ";minAge=" + to_string(minAge / 10) + to_string(minAge % 10) + ";maxAge=" + to_string(maxAge / 10) + to_string(maxAge % 10) + ";";
}

void Children::showProgram()
{
	coutReleaseTime();
	cout << "Минимальный возраст:\t" << minAge << " лет" << endl;
	cout << "Максимальный возраст:\t" << maxAge << " лет" << endl;
}

int Children::getType()
{
	return type;
}
