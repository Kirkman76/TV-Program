#include "DayProgram.h"



DayProgram::DayProgram(int year, int month, int day)
{
	tvDate.setYear(year);
	tvDate.setMonth(month);
	tvDate.setDay(day);
}


DayProgram::~DayProgram()
{
	programs.clear();
}

void DayProgram::setTvDate(int year, int month, int day)
{
	tvDate.setYear(year);
	tvDate.setMonth(month);
	tvDate.setDay(day);
}

Date DayProgram::getTvDate()
{
	return tvDate;
}

void DayProgram::addNewProgram(TVprogram &obj)
{
	programs.push_back(&obj);
}

void DayProgram::showAllPrograms()
{
	TVprogram* tmp;
	for (vector <TVprogram*>::iterator i = programs.begin(); i != programs.end(); ++i) {
		tmp = *i;
		tmp->showProgram();
		cout << endl;
	}
}

void DayProgram::sortByType()
{
	TVprogram* tmp;
	for (int i = 0; i < programs.size(); i++)
	{
		for (int j = i + 1; j < programs.size(); j++)
		{
			if (programs[j]->getType() < programs[i]->getType())
			{
				tmp = programs[j];
				programs[j] = programs[i];
				programs[i] = tmp;
			}
		}
	}
}

void DayProgram::sortByTime()
{
	TVprogram* tmp;
	for (int i = 0; i < programs.size(); i++)
	{
		for (int j = i + 1; j < programs.size(); j++)
		{
			if (programs[j]->getReleaseTime() < programs[i]->getReleaseTime())
			{
				tmp = programs[j];
				programs[j] = programs[i];
				programs[i] = tmp;
			}
		}
	}
}

int DayProgram::findByName(string name)
{
	for (int i = 0; i < programs.size(); i++)
	{
		if (programs[i]->getName() == name) {
			programs[i]->showProgram();
			cout << endl;
			return i;
		}
	}
}

void DayProgram::findByTime(int approximateTime)
{
	for (int i = 0; i < programs.size(); i++)
	{
		if (programs[i]->getReleaseTime().getHour() >= approximateTime - 1 && programs[i]->getReleaseTime().getHour() <= approximateTime + 1) {
			programs[i]->showProgram();
			cout << endl;
		}
	}
}

void DayProgram::delProgram(string name)
{
	vector <TVprogram*>::iterator i = programs.begin();
	TVprogram* tmp;
	bool erase = false;
	for (; i != programs.end(); ++i) {
		tmp = *i;
		if (tmp->getName() == name) {
			erase = true;
			break;
		}
	}
	if (erase) programs.erase(i);
}

void DayProgram::clearProgram()
{
	programs.clear();
}

void DayProgram::saveToFile()
{
	const string path = "prog_" + to_string(tvDate.getDay()) + "_" + to_string(tvDate.getMonth()) + " " + to_string(tvDate.getYear()) + ".txt";
	
	ofstream fout;
	fout.open(path);

	try
	{
		if (!fout.is_open()) {
			throw exception("������ �������� �����!/n");
		}
		for (int i = programs.size() - 1; i > -1; i--)
		{
			fout << programs[i]->toString();
		}

		fout.close();
	}
	catch (const exception& ex)
	{
		cout << ex.what();
	}


}

void DayProgram::loadFromFile(string path)
{
	ifstream fin;
	fin.open(path);
	string tmp1 = "";
	string tmp2 = "";
	try
	{
		if (!fin.is_open()) {
			throw exception("������ �������� �����!/n");
		}
		while (!fin.eof())
		{
			fin >> tmp1;
			tmp2 += tmp1; // ������� ���� ���� � ������
		}
			
		fin.close();
	}
	catch (const exception& ex)
	{
		cout << ex.what();
	}


	////////////������
	int numTmp = 0; // ���������� ��� ��������� ������� �������� �� ������
	while (tmp2.size() != 0)
	{
		numTmp = int(tmp2[5]) - 48;

		if (numTmp == 4) {

			string name; // ���������� ���
			int strName = 0; // ��������������� ���������� ��� �������� ����� name
			strName = (int(tmp2[12]) - 48) * 10 + (int(tmp2[13]) - 48);

			for (int i = 14; i < 14 + strName; i++) // ��������� name
			{
				name.push_back(tmp2[i]);
			}
			
			int hours = (int(tmp2[13 + strName + 14]) - 48) * 10 + (int(tmp2[13 + strName + 15]) - 48); // ���� hours

			int minutes = (int(tmp2[13 + strName + 17]) - 48) * 10 + (int(tmp2[13 + strName + 18]) - 48); // ������ minutes

			string directBox; // �������� ������
			int strBox = 0;
			strBox = (int(tmp2[13 + strName + 30]) - 48) * 10 + (int(tmp2[13 + strName + 31]) - 48);

			for (int i = 13 + strName + 32; i < 13 + strName + 32 + strBox; i++) // ��������� ��������
			{
				directBox.push_back(tmp2[i]);
			}

			int releaseYear = (int(tmp2[13 + strName + 31 + strBox + 14]) - 48) * 1000 + (int(tmp2[13 + strName + 31 + strBox + 15]) - 48) * 100 + (int(tmp2[13 + strName + 31 + strBox + 16]) - 48) * 10 + (int(tmp2[13 + strName + 31 + strBox + 17]) - 48);

			programs.push_back(new Movie (name, hours, minutes, directBox, releaseYear)); // ������ ����� �������� � �������������

			tmp2.erase(0, 13 + strName + 31 + strBox + 19); // ������� ��������� ������ �� ������������� ������
		}

		else if (numTmp == 1) {

			string name; // ���������� ���
			int strName = 0; // ��������������� ���������� ��� �������� ����� name
			strName = (int(tmp2[12]) - 48) * 10 + (int(tmp2[13]) - 48);

			for (int i = 14; i < 14 + strName; i++) // ��������� name
			{
				name.push_back(tmp2[i]);
			}

			int hours = (int(tmp2[13 + strName + 14]) - 48) * 10 + (int(tmp2[13 + strName + 15]) - 48); // ���� hours

			int minutes = (int(tmp2[13 + strName + 17]) - 48) * 10 + (int(tmp2[13 + strName + 18]) - 48); // ������ minutes
			
			int minAge = (int(tmp2[13 + strName + 27]) - 48) * 10 + (int(tmp2[13 + strName + 28]) - 48); // ����������� �������
			
			int maxAge = (int(tmp2[13 + strName + 37]) - 48) * 10 + (int(tmp2[13 + strName + 38]) - 48); // ������������ �������
			
			programs.push_back(new Children (name, hours, minutes, minAge, maxAge)); // ������ ����� �������� � �������������

			tmp2.erase(0, 13 + strName + 40); // ������� ��������� ������ �� ������������� ������
			}

		else if (numTmp == 3) {

			string name; // ���������� ���
			int strName = 0; // ��������������� ���������� ��� �������� ����� name
			strName = (int(tmp2[12]) - 48) * 10 + (int(tmp2[13]) - 48);

			for (int i = 14; i < 14 + strName; i++) // ��������� name
			{
				name.push_back(tmp2[i]);
			}

			int hours = (int(tmp2[13 + strName + 14]) - 48) * 10 + (int(tmp2[13 + strName + 15]) - 48); // ���� hours

			int minutes = (int(tmp2[13 + strName + 17]) - 48) * 10 + (int(tmp2[13 + strName + 18]) - 48); // ������ minutes

			string theme; // ���� ���
			int strTheme = 0; // ��������������� ���������� ��� �������� ����� theme
			strTheme = (int(tmp2[13 + strName + 26]) - 48) * 10 + (int(tmp2[13 + strName + 27]) - 48); // ������ � �������������� ����� theme �� ��������� ������

			for (int i = 13 + strName + 28; i < 13 + strName + 28 + strTheme; i++) // ��������� ���� ���
			{
				theme.push_back(tmp2[i]);
			}

			programs.push_back(new Show (name, hours, minutes, theme)); // ������ ����� �������� � �������������

			tmp2.erase(0, 13 + strName + 28 + strTheme + 1); // ������� ��������� ������ �� ������������� ������
			}

		else if (numTmp == 2) {

			string name; // ���������� ���
			int strName = 0; // ��������������� ���������� ��� �������� ����� name
			strName = (int(tmp2[12]) - 48) * 10 + (int(tmp2[13]) - 48);

			for (int i = 14; i < 14 + strName; i++) // ��������� name
			{
				name.push_back(tmp2[i]);
			}

			int hours = (int(tmp2[13 + strName + 14]) - 48) * 10 + ((int(tmp2[13 + strName + 15]) - 48)); // ���� hours

			int minutes = (int(tmp2[13 + strName + 17]) - 48) * 10 + ((int(tmp2[13 + strName + 18]) - 48)); // ������ minutes

			string science; // �����
			int strScience = 0; // ��������������� ���������� ��� �������� ����� science
			strScience = (int(tmp2[13 + strName + 28]) - 48) * 10 + ((int(tmp2[13 + strName + 29]) - 48)); // ������ � �������������� ����� science �� ��������� ������

			for (int i = 13 + strName + 30; i < 13 + strName + 30 + strScience; i++) // ��������� �����
			{
				science.push_back(tmp2[i]);
			}

			programs.push_back(new Education (name, hours, minutes, science)); // ������ ����� �������� � �������������

			tmp2.erase(0, 13 + strName + 30 + strScience + 1); // ������� ��������� ������ �� ������������� ������
		}
	}
}
