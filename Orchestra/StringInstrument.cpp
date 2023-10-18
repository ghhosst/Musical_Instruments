#include "StringInstrument.h"
using std::cout;
using std::cin;
using std::endl;

StringInstrument::StringInstrument() {
	int choiceStringInst;
	int NumUnitsStringInst, CostStringInst;
	int lenString;
	do {
		system("cls");
		cout << "������� ������ � �������� �����������" << endl
			<< "1) ��������" << endl
			<< "2) ��� ���������" << endl
			<< "3) ���������� ������ � ��������" << endl
			<< "4) ���������" << endl
			<< "5) ������������ �������������" << endl
			<< "6) ������� ��������� ��������" << endl
			<< "7) �����" << endl
			<< "��������� �����: ";
		cin >> choiceStringInst;


		switch (choiceStringInst) {
		case 1:
			system("cls");
			cout << "�������� ���������\n";
			cout << "������� ��������:\n" << endl;
			SetNameInstrument(getString(&lenString));
			break;
		case 2:
			system("cls");
			cout << "�������� ����������\n";
			cout << "������� ��� ���������:\n" << endl;
			SetFullNameOwner(getString(&lenString));
			break;
		case 3:
			system("cls");
			cout << "�������� ����������\n";
			cout << "������� ���������� ������ � ��������: ";
			cin >> NumUnitsStringInst;
			SetNumUnitsOrchestra(NumUnitsStringInst);
			break;
		case 4:
			system("cls");
			cout << "�������� ����������\n";
			cout << "������� ���������: ";
			cin >> CostStringInst;
			SetCost(CostStringInst);
			break;
		case 5:
			system("cls");
			cout << "�������� ����������\n";
			cout << "������� ������������ �������������: \n" << endl;
			NameManufacture = getString(&lenString);
			break;
		case 6:
			system("cls");
			cout << "�������� ����������\n";
			cout << "�������� ������� ��������� ��������:\n" << endl;
			TextDescription = getString(&lenString);
			break;
		default:
			break;
		}
	} while (choiceStringInst != 7);
}

char* StringInstrument::GetNameManufacture() {
	return this->NameManufacture;
}

void StringInstrument::SetNameManufacture(char* NameManufacture) {
	this->NameManufacture = NameManufacture;
}

char* StringInstrument::GetTextDescription() {
	return this->TextDescription;
}

void StringInstrument::SetTextDescription(char* TextDescription) {
	this->TextDescription = TextDescription;
}

void StringInstrument::Sound() {
	std::cout << "\n\n������������\n\n";
}