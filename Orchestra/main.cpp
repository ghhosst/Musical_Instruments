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
		cout << "�������" << endl
			 << "1) �������� ����������" << endl
			 << "2) ������� ����������" << endl
			 << "3) ������� �� ����� ��� ��������� �����������" << endl
			 << "4) �������� ������ �� �����������" << endl
			 << "5) ��������� � ����" << endl
			 << "6) ��������� �� �����" << endl
			 << "7) ����� �� ���������" << endl
			 << "��������� �����: ";
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
				throw MyException("\n\n������������ �����!!!\n����������, �������� ����� ���� �� 1 �� 7.\n\n");
				break;
			}
		}
		catch (const std::istream::failure& ex) {
			system("cls");
			cout << "\n\n������� ������������ �������� !!!" << endl
				<< ex.what() << "\n" << ex.code() << endl
				<< "��������� ����...\n\n";
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