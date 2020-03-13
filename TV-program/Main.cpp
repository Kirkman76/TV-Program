#include"DayProgram.h"
#include"Children.h"
#include"Education.h"
#include"Movie.h"
#include"Show.h"

int main() {
	setlocale(LC_CTYPE, "ru");

	//Children prog1("������", 19, 30, 0, 99);

	//Movie prog2("������", 21, 45, "��������������_������", 1994);

	//Education prog3("������", 12, 25, "����������");

	//Show prog4("�������", 11, 00, "���������");

	//Children prog5(prog1);

	DayProgram channel1(2020, 03, 5);

	channel1.loadFromFile("prog_5_3 2020.txt");

	for (;;) {
		cout << "\t\t\t��������� �����������\n";
		cout << "\t\t����:\n";
		cout << "������� ����: " << channel1.getTvDate() << endl;
		cout << "1. �������� ��������� �����������.\n";
		cout << "2. ������� ������������� �� ����� ����.\n";
		cout << "3. ��������� ������������� �� ����.\n";
		cout << "4. �������� ������������.\n";
		cout << "5. ������� ������������.\n";
		cout << "6. ��������� �������������.\n";
		cout << "7. ����� �� �������� ������������.\n";
		cout << "8. ����� �� ������� ������ � ����.\n";
		cout << "9. ���������� �� ������� ������ � ����.\n";
		cout << "10. ���������� ����� ������������.\n";
		cout << "11. �����.\n";

		bool exit = false; // ������ ��� ������
		// ���������� ��� ������ ����
		int select;      // 1
		string selName;  // 2
		string selOther; // 3
		cin >> select;

		switch (select)
		{
		case 1:
			channel1.showAllPrograms();
			break;

		case 2:
			cout << "������� ����:\n";
			cout << "���: ";
			int year;
			cin >> year;
			cout << "�����: ";
			int month;
			cin >> month;
			cout << "����: ";
			int day;
			cin >> day;

			channel1.clearProgram();
			channel1.setTvDate(year, month, day);
			break;

		case 3:
			cout << "������� ����:\n";
			cout << "���: ";
			cin >> year;
			cout << "�����: ";
			cin >> month;
			cout << "����: ";
			cin >> day;

			channel1.clearProgram();
			channel1.loadFromFile("prog_" + to_string(day) + "_" + to_string(month) + " " + to_string(year) + ".txt");

			break;

		case 4:
			cout << "�������� ��� ��������: �������(1), ���(2), ����(3), ���������������(4)\n";
			cin >> select;
			cout << "������� ��������: ";
			cin >> selName;
			cout << "������� ����� ������ � ����:\n";
			cout << "�����: ";
			int hours;
			cin >> hours;
			cout << "�����: ";
			int minutes;
			cin >> minutes;

			if (select == 1) {
				cout << "������� ����������� �������: ";
				int minAge;
				cin >> minAge;
				cout << "������� ������������ �������: ";
				int maxAge;
				cin >> maxAge;
				channel1.addNewProgram(*(new Children(selName, hours, minutes, minAge, maxAge)));
			}
			else if (select == 2) {
				cout << "������� ���� ���: ";
				cin >> selOther;
				channel1.addNewProgram(*(new Show(selName, hours, minutes, selOther)));
			}
			else if (select == 3) {
				cout << "������� �������� ������: ";
				cin >> selOther;
				cout << "������� ��� ������: ";
				cin >> select;
				channel1.addNewProgram(*(new Movie(selName, hours, minutes, selOther, select)));
			}
			else if (select == 4) {
				cout << "������� �������� ������� ����� :";
				cin >> selOther;
				channel1.addNewProgram(*(new Education(selName, hours, minutes, selOther)));
			}
			break;

		case 5:
			cout << "������� ��������: ";
			cin >> selName;
			channel1.delProgram(selName);
			break;

		case 6:
			channel1.saveToFile();
			break;

		case 7:
			cout << "������� �������� ������������: ";
			cin >> selName;
			channel1.findByName(selName);
			break;
		case 8:
			cout << "������� ����� ������ � ����:\n";
			cout << "�����: ";
			hours;
			cin >> hours;
			channel1.findByTime(hours);
			break;

		case 9:
			channel1.sortByTime();
			break;

		case 10:
			channel1.sortByType();
			break;

		case 11:
			exit = true;
			break;


		default:
			break;
		}

		if (exit) break;
		system("pause");
		system("cls");
	}

	

	return 0;
}