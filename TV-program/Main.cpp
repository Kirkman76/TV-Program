#include"DayProgram.h"
#include"Children.h"
#include"Education.h"
#include"Movie.h"
#include"Show.h"

int main() {
	setlocale(LC_CTYPE, "ru");

	//Children prog1("Сказки", 19, 30, 0, 99);

	//Movie prog2("Хищник", 21, 45, "фантастический_боевик", 1994);

	//Education prog3("Космос", 12, 25, "Космология");

	//Show prog4("Таланты", 11, 00, "Полуфинал");

	//Children prog5(prog1);

	DayProgram channel1(2020, 03, 5);

	channel1.loadFromFile("prog_5_3 2020.txt");

	for (;;) {
		cout << "\t\t\tПрограмма телепередач\n";
		cout << "\t\tМеню:\n";
		cout << "Выбрана дата: " << channel1.getTvDate() << endl;
		cout << "1. Просмотр программы телепередач.\n";
		cout << "2. Создать телепрограмму на новый день.\n";
		cout << "3. Загрузить телепрограмму по дате.\n";
		cout << "4. Добавить телепередачу.\n";
		cout << "5. Удалить телепередачу.\n";
		cout << "6. Сохранить телепрограмму.\n";
		cout << "7. Поиск по названию телепередачи.\n";
		cout << "8. Поиск по времени выхода в эфир.\n";
		cout << "9. Сортировка по времени выхода в эфир.\n";
		cout << "10. Сортировка жанру телепередачи.\n";
		cout << "11. Выход.\n";

		bool exit = false; // маркер для выхода
		// переменные для выбора меню
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
			cout << "Введите дату:\n";
			cout << "Год: ";
			int year;
			cin >> year;
			cout << "Месяц: ";
			int month;
			cin >> month;
			cout << "День: ";
			int day;
			cin >> day;

			channel1.clearProgram();
			channel1.setTvDate(year, month, day);
			break;

		case 3:
			cout << "Введите дату:\n";
			cout << "Год: ";
			cin >> year;
			cout << "Месяц: ";
			cin >> month;
			cout << "День: ";
			cin >> day;

			channel1.clearProgram();
			channel1.loadFromFile("prog_" + to_string(day) + "_" + to_string(month) + " " + to_string(year) + ".txt");

			break;

		case 4:
			cout << "Выберите тип передачи: детская(1), шоу(2), кино(3), образовательная(4)\n";
			cin >> select;
			cout << "Введите название: ";
			cin >> selName;
			cout << "Введите время выхода в эфир:\n";
			cout << "Часов: ";
			int hours;
			cin >> hours;
			cout << "Минут: ";
			int minutes;
			cin >> minutes;

			if (select == 1) {
				cout << "Введите минимальный возраст: ";
				int minAge;
				cin >> minAge;
				cout << "Введите максимальный возраст: ";
				int maxAge;
				cin >> maxAge;
				channel1.addNewProgram(*(new Children(selName, hours, minutes, minAge, maxAge)));
			}
			else if (select == 2) {
				cout << "Введите тему шоу: ";
				cin >> selOther;
				channel1.addNewProgram(*(new Show(selName, hours, minutes, selOther)));
			}
			else if (select == 3) {
				cout << "Введите описание фильма: ";
				cin >> selOther;
				cout << "Введите год выхода: ";
				cin >> select;
				channel1.addNewProgram(*(new Movie(selName, hours, minutes, selOther, select)));
			}
			else if (select == 4) {
				cout << "Введите название области науки :";
				cin >> selOther;
				channel1.addNewProgram(*(new Education(selName, hours, minutes, selOther)));
			}
			break;

		case 5:
			cout << "Введите название: ";
			cin >> selName;
			channel1.delProgram(selName);
			break;

		case 6:
			channel1.saveToFile();
			break;

		case 7:
			cout << "Введите название телепередачи: ";
			cin >> selName;
			channel1.findByName(selName);
			break;
		case 8:
			cout << "Введите время выхода в эфир:\n";
			cout << "Часов: ";
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