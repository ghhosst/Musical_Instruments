//#include "BaseOrchestra.h"
#include "Keeper.h"
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251"); 

	Keeper TheKeeper;

	int choice1, choice2;
	int choiceInstrument;

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
			cin >> choiceInstrument;
			
			TheKeeper.Add(choiceInstrument);
			break;
		default:
			break;
		}


	} while (choice1 != 5);


	return 0; 
}