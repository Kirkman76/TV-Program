#include "Show.h"



Show::Show(string name, int hours, int minutes, string theme)
{
	try {
		setName(name);
		setReleaseTime(hours, minutes);
		setTheme(theme);
		type = SHOW; // ÿŒ”
	}
	catch (StringException& ex) {
		cout << ex.message();
	}
}


Show::~Show()
{
}

Show::Show(Show& obj)
{
	this->name = obj.name;
	this->releaseTime = obj.releaseTime;
	this->theme = obj.theme;
	this->type = obj.type;
}

void Show::setTheme(string theme)
{
	if (theme == "") {
		throw StringException();
	}
	this->theme = theme;
}

string Show::getTheme()
{
	return theme;
}

string Show::toString()
{
	return toStringRT() + ";theme=" + to_string(theme.size() / 10) + to_string(theme.size() % 10) + theme + ";";
}

void Show::showProgram()
{
	coutReleaseTime();
	cout << "“ÂÏ‡:\t\t\t" << theme << endl;
}

int Show::getType()
{
	return type;
}
