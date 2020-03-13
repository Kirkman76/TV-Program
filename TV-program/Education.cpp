#include "Education.h"



Education::Education(string name, int hours, int minutes, string science)
{
	try {
		setName(name);
		setScience(science);
		setReleaseTime(hours, minutes);
		type = EDUC; // Œ¡–¿«Œ¬¿“≈À‹Õ¿ﬂ
	}
	catch (StringException& ex) {
		cout << ex.message();
	}
}


Education::~Education()
{
}

Education::Education(Education& obj)
{
	this->name = obj.name;
	this->releaseTime = obj.releaseTime;
	this->science = obj.science;
	this->type = obj.type;
}

void Education::setScience(string science)
{
	if (science == "") {
		throw StringException();
	}
	this->science = science;
}

string Education::getScience()
{
	return science;
}

string Education::toString()
{
	return toStringRT() + ";science=" + to_string(science.size() / 10) + to_string(science.size() % 10) + science + ";";
}

void Education::showProgram()
{
	coutReleaseTime();
	cout << "Õ‡ÛÍ‡:\t\t\t" << science << endl;
}

int Education::getType()
{
	return type;
}
