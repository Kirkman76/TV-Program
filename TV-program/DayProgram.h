#pragma once
#include<vector>
#include<fstream>
#include"Date.h"
#include"TVprogram.h"
#include"Children.h"
#include"Show.h"
#include"Education.h"
#include"Movie.h"

class DayProgram
{
private:
	Date tvDate;				  // дата программы передач (на какой день)
	vector <TVprogram*> programs; // список передач; (контейнер vector выбран по причине, т.к. предусмотрена сортировка
								  //   и поиск, вектор будет работать гораздо быстрее list)
public:
	DayProgram(int year, int month, int day);
	~DayProgram();

	void setTvDate(int year, int month, int day);
	Date getTvDate();

	void addNewProgram(TVprogram &obj);
	void showAllPrograms();

	void sortByType();					 // сортировка по типу передачи
	void sortByTime();					 // сортировка по времени выхода в эфир
	int findByName(string name);		 // поиск по названию
	void findByTime(int approximateTime);// поиск по приблизительному времени (часов)
	void delProgram(string name);		 // удаление программы по названию
	void clearProgram();                 // удаление всей телепрограммы
	void saveToFile();					 // запись телепрограммы в файл
	void loadFromFile(string path);		 // чтение телепрограммы из файла
};

