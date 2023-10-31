#define _CRT_SECURE_NO_WARNINGS  
#include "Keeper.h"
#include <iostream>
using std::cout, std::cin, std::endl, std::streamsize, std::numeric_limits;

int main() {
	cin.exceptions(std::istream::failbit); 
	setlocale(LC_ALL, "Russian");
	system("chcp 1251"); 
	
	Keeper TheKeeper;

	int choice1;

	do {
		system("cls");
		cout << "Оркестр" << endl
			 << "1) Добавить инструмент" << endl
			 << "2) Удалить инструмент" << endl
			 << "3) Вывести на экран все имеющиеся инструменты" << endl
			 << "4) Изменить данные об инструменте" << endl
			 << "5) Сохранить в файл" << endl
			 << "6) Загрузить из файла" << endl
			 << "7) Выйти из программы" << endl
			 << "Выбранный пункт: ";
		try {

			cin >> choice1;


			switch (choice1) {
			case 1:
				++TheKeeper;  
				break;
			case 2:
				--TheKeeper;
				break;
			case 3:
				TheKeeper.ShowOrchestra();
				break;
			case 4:
				TheKeeper.СhangeInstrument();
				break;
			case 5:
				TheKeeper.Save();
				break;
			case 6:
				TheKeeper.Load();
				break;
			case 7:
				break;
			default:
				throw MyException("\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт меню от 1 до 7.\n\n");
				break;
			}
		}
		catch (const std::istream::failure& ex) {
			system("cls");
			cout << "\n\nВведено некорректное значение !!!" << endl
				<< ex.what() << "\n" << ex.code() << endl
				<< "Повторите ввод...\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			system("pause");
		}
		catch (const MyException& ex) {
			cout << ex.what();
			system("pause");
		}

	} while (choice1 != 7);



	return 0; 
}