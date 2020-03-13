#pragma once
#include "TVprogram.h"
class Movie :
	public TVprogram
{
private:
	string directBox; //описание фильма
	int releaseYear; // год выхода
	types type;


public:
	Movie(string name, int hours, int minutes, string directBox, int releaseYear);
	~Movie();
	Movie(Movie& obj);

	void setDirectBox(string directBox);
	string getDirectBox();
	void setReleaseYear(int releaseYear);
	int getReleaseYear();

	string toString() override;
	void showProgram() override;
	int getType() override;
};

