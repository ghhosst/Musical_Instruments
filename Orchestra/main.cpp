#include "BaseOrchestra.h"
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	

	int choice1, choice2;

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