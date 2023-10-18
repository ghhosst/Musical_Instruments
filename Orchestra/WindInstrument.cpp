#include "WindInstrument.h"
using std::cout;
using std::cin;
using std::endl;

WindInstrument::WindInstrument() {
	int choiceWind;
	int NumUnitsWind, CostWind;
	int lenString;
	do {
		system("cls");
		cout << "������� ������ � ������� �����������" << endl
			<< "1) ��������" << endl
			<< "2) ��� ���������" << endl
			<< "3) ���������� ������ � ��������" << endl
			<< "4) ���������" << endl
			<< "5) ������������ �������������" << endl
			<< "6) ����� ������� ������������" << endl
			<< "7) �����" << endl
			<< "��������� �����: ";
		cin >> choiceWind;


		switch (choiceWind) {
		case 1:
			system("cls");
			cout << "������� ���������\n";
			cout << "������� ��������:\n" << endl;
			SetNameInstrument(getString(&lenString));
			break;
		case 2:
			system("cls");
			cout << "������� ����������\n";
			cout << "������� ��� ���������:\n" << endl;
			SetFullNameOwner(getString(&lenString));
			break;
		case 3:
			system("cls");
			cout << "������� ����������\n";
			cout << "������� ���������� ������ � ��������: ";
			cin >> NumUnitsWind;
			SetNumUnitsOrchestra(NumUnitsWind);
			break;
		case 4:
			system("cls");
			cout << "������� ����������\n";
			cout << "������� ���������: ";
			cin >> CostWind;
			SetCost(CostWind);
			break;
		case 5:
			system("cls");
			cout << "������� ����������\n";
			cout << "������� ������������ �������������: \n" << endl;
			NameManufacture = getString(&lenString);
			break;
		case 6:
			system("cls");
			cout << "������� ����������\n";
			cout << "�������� ����� ������� ����������� � ���� �����������:\n" << endl;
			Defects = getString(&lenString);
			break;
		case 7:
			break;
		default:
			break;
		}
	} while (choiceWind != 7);
}

char* WindInstrument::GetNameManufacture() {
	return this->NameManufacture;
}

void WindInstrument::SetNameManufacture(char* NameManufacture) {
	this->NameManufacture = NameManufacture;
}

char* WindInstrument::GetDefects() {
	return this->Defects;
}

void WindInstrument::SetDefects(char* Defects) {
	this->Defects = Defects;
}

void WindInstrument::Sound() {
	std::cout << "\n\n����������\n\n";
}