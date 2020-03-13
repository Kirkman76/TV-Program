#include "Movie.h"



Movie::Movie(string name, int hours, int minutes, string directBox, int releaseYear)
{
	try {
		setName(name);
		setDirectBox(directBox);
		setReleaseTime(hours, minutes);
		setReleaseYear(releaseYear);
		type = MOVI; // ФИЛЬМ
	}
	catch (StringException& ex) {
		cout << ex.message();
	}
}


Movie::~Movie()
{
}

Movie::Movie(Movie& obj)
{
	this->name = obj.name;
	this->releaseTime = obj.releaseTime;
	this->directBox = obj.directBox;
	this->releaseYear = obj.releaseYear;
	this->type = obj.type;
}

void Movie::setDirectBox(string directBox)
{
	if (directBox == "") {
		throw StringException();
	}
	this->directBox = directBox;
}

string Movie::getDirectBox()
{
	return directBox;
}

void Movie::setReleaseYear(int releaseYear)
{
	Date tmp;
	try
	{
		if (releaseYear < 1800 || releaseYear > tmp.getYear()) {
			throw exception("Неверно введён год!\n");
		}
		this->releaseYear = releaseYear;
	}
	catch (const exception& ex)
	{
		cout << ex.what();
	}
}

int Movie::getReleaseYear()
{
	return releaseYear;
}

string Movie::toString()
{
	return toStringRT() + ";directBox=" + to_string(directBox.size()) + directBox + ";releaseYear=" + to_string(releaseYear) + ";";
}

void Movie::showProgram()
{
	coutReleaseTime();
	cout << "Описание:\t\t" << directBox << endl;
	cout << "Год выхода:\t\t" << releaseYear << endl;
}

int Movie::getType()
{
	return type;
}
