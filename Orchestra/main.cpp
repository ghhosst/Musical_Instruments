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
		cout << "�������" << endl
			 << "1) �������� ����������" << endl
			 << "2) ������� ����������" << endl
			 << "3) ������� �� ����� ��� ��������� �����������" << endl
			 << "4) �������� ������ �� �����������" << endl
			 << "5) ����� �� ���������" << endl
			 << "��������� �����: ";
		cin >> choice1;

		switch (choice1){
		case 1:
			system("cls");
			cout << "����� ���������� �������� � ������� ?" << endl
			 	 << "1) �������" << endl
				 << "2) ��������" << endl
				 << "3) �������" << endl
				 << "��������� �����: ";
			cin >> choiceInstrument;
			
			TheKeeper.Add(choiceInstrument);
			break;
		default:
			break;
		}


	} while (choice1 != 5);


	return 0; 
}