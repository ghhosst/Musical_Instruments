#define _CRT_SECURE_NO_WARNINGS  
#include "Keeper.h"
#include <iostream>
using std::cout, std::cin, std::endl;

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251"); 

	Keeper TheKeeper;

	int choice1;

	do {
		system("cls");
		cout << "�������" << endl
			 << "1) �������� ����������" << endl
			 << "2) ������� ����������" << endl
			 << "3) ������� �� ����� ��� ��������� �����������" << endl
			 << "4) �������� ������ �� �����������" << endl
			 << "5) ��������� � ����" << endl
			 << "6) ��������� �� �����" << endl
			 << "7) ����� �� ���������" << endl
			 << "��������� �����: ";
		cin >> choice1;

		switch (choice1){
		case 1:
			TheKeeper.Add();
			break;
		case 2:
			TheKeeper.DeleteInstrument();
			break;
		case 3:
			TheKeeper.ShowOrchestra();
			break;
		case 4:
			TheKeeper.�hangeInstrument();
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
			cout << "\n\n������������ �����!!!\n����������, �������� ����� ���� �� 1 �� 7.\n\n";
			system("pause");
			break;
		}
	} while (choice1 != 7);


	
	return 0; 
}