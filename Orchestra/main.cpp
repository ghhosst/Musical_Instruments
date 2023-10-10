#include "BaseOrchestra.h"
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	

	int choice1, choice2;

	do {
		system("cls");
		cout << "Оркестр" << endl
			 << "1) Добавить инструмент" << endl
			 << "2) Удалить инструмент" << endl
			 << "3) Вывести на экран все имеющиеся инструменты" << endl
			 << "4) Изменить данные об инструменте" << endl
			 << "5) Выйти из программы" << endl
			 << "Выбранный пункт: ";
		cin >> choice1;

		switch (choice1){
		case 1:
			system("cls");
			cout << "Какой инструмент добавить в оркестр ?" << endl
			 	 << "1) Ударный" << endl
				 << "2) Струнный" << endl
				 << "3) Духовой" << endl
				 << "Выбранный пункт: ";
			cin >> choice2;
			
			switch (choice2){
			case 1:

				break;
			case 2:

				break;
			case 3:

				break;
			default:
				break;
			}
			break;
		default:
			break;
		}


	} while (choice1 != 5);


	return 0; 
}