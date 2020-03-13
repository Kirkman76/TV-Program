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
	Date tvDate;				  // ���� ��������� ������� (�� ����� ����)
	vector <TVprogram*> programs; // ������ �������; (��������� vector ������ �� �������, �.�. ������������� ����������
								  //   � �����, ������ ����� �������� ������� ������� list)
public:
	DayProgram(int year, int month, int day);
	~DayProgram();

	void setTvDate(int year, int month, int day);
	Date getTvDate();

	void addNewProgram(TVprogram &obj);
	void showAllPrograms();

	void sortByType();					 // ���������� �� ���� ��������
	void sortByTime();					 // ���������� �� ������� ������ � ����
	int findByName(string name);		 // ����� �� ��������
	void findByTime(int approximateTime);// ����� �� ���������������� ������� (�����)
	void delProgram(string name);		 // �������� ��������� �� ��������
	void clearProgram();                 // �������� ���� �������������
	void saveToFile();					 // ������ ������������� � ����
	void loadFromFile(string path);		 // ������ ������������� �� �����
};

