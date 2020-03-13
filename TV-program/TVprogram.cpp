#include "TVprogram.h"

void TVprogram::coutReleaseTime()
{
	cout << "��������:\t\t" << name << endl;
	cout << "����� ������:\t\t" << releaseTime.getHour() << " � " << releaseTime.getMinutes() / 10 << releaseTime.getMinutes() % 10 << " ���" << endl;
}

string TVprogram::toStringRT()
{
	return "type=" + to_string(getType()) + ";name=" + to_string(name.size() / 10) + to_string(name.size() % 10) + name + ";releaseTime=" + to_string(releaseTime.getHour() / 10) + to_string(releaseTime.getHour() % 10) + ":" + to_string(releaseTime.getMinutes() / 10) + to_string(releaseTime.getMinutes() % 10);
}

void TVprogram::setName(string name)
{
	if (name == "") {
		throw StringException();
	}
		this->name = name;
	
}

string TVprogram::getName()
{
	return name;
}

void TVprogram::setReleaseTime(int hours, int minutes)
{
	try
	{
		if ((hours < 0 || hours > 23) || (minutes < 0 || minutes > 59)) {
			throw exception ("������� ������ �����!\n");
		}
		releaseTime.setHour(hours);
		releaseTime.setMinutes(minutes);
		releaseTime.setSeconds(0);
	}
	catch (const exception& ex)
	{
		cout << ex.what();
	}
}

Time_ TVprogram::getReleaseTime()
{
	return releaseTime;
}
