#define _CRT_SECURE_NO_WARNINGS  
#include "StringInstrument.h"
using std::cout; 
using std::cin; 
using std::endl;

StringInstrument::StringInstrument() {
	std::cout << "\n----|������ ����������� ������ StringInstrument (��� ����������)|----\n";
	system("pause");

	const char* initStr = "\t-";
	
	NameManufacture = new char[sizeof(initStr)];
	strcpy(NameManufacture, initStr);

	TextDescription = new char[sizeof(initStr)];
	strcpy(TextDescription, initStr);

	int choiceStringInst;
	int NumUnitsStringInst;
	float CostStringInst;
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
		case 7:
			break;
		default:
			cout << "\n\n������������ �����!!!\n����������, �������� ����� �� 1 �� 7.\n\n";
			system("pause");
			break;
		}
	} while (choiceStringInst != 7);
}

StringInstrument::StringInstrument(char file) { 
	std::cout << "\n----|������ ����������� ������ StringInstrument (� ����������)|----\n";
	system("pause");

	NameManufacture = nullptr;
	TextDescription = nullptr;
}

StringInstrument::StringInstrument(const StringInstrument& other) {
	std::cout << "\n----|������ ����������� ������ StringInstrument (�����������)|----\n";
	system("pause");

	strcpy(this->NameManufacture, other.NameManufacture);
	strcpy(this->TextDescription, other.TextDescription);
}

StringInstrument::~StringInstrument() {
	std::cout << "\n----|������ ���������� ������ StringInstrument|----\n";
	system("pause");

	delete[] NameManufacture;
	NameManufacture = nullptr;
	delete[] TextDescription;
	TextDescription = nullptr; 
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

void StringInstrument::ShowInstrument() {
	cout << "\n�������� ����������\n\n"
		<< "��������: " << GetNameInstrument() << endl
		<< "��� ���������: " << GetFullNameOwner() << endl
		<< "���������� ������ � ��������: " << GetNumUnitsOrchestra() << endl
		<< "���������: " << GetCost() << endl
		<< "�������������: " << GetNameManufacture() << endl
		<< "��������: " << GetTextDescription() << endl;
}

void StringInstrument::Change() {
	int lenString;
	int choiceChangePerc;
	int NumUnitsPercussion;
	float CostPercussion;
	cout << "\n\n�������� �����, ������� ������ ��������..." << endl
		<< "1) ��������" << endl
		<< "2) ��� ���������" << endl
		<< "3) ���������� ������ � ��������" << endl
		<< "4) ���������" << endl
		<< "5) �������������" << endl
		<< "6) ��������" << endl
		<< "��������� �����: ";
	cin >> choiceChangePerc;
	switch (choiceChangePerc) {
	case 1:
		cout << "\n������� ��������: ";
		SetNameInstrument(getString(&lenString));
		break;
	case 2:
		cout << "\n������� ��� ���������: ";
		SetFullNameOwner(getString(&lenString));
		break;
	case 3:
		cout << "������� ���������� ������ � ��������: ";
		cin >> NumUnitsPercussion;
		SetNumUnitsOrchestra(NumUnitsPercussion);
		break;
	case 4:
		cout << "������� ���������: ";
		cin >> CostPercussion;
		SetCost(CostPercussion);
		break;
	case 5:
		cout << "������� ������������ �������������: ";
		NameManufacture = getString(&lenString); 
		break;
	case 6:
		cout << "�������� ������� ��������� ��������: ";
		TextDescription = getString(&lenString);
		break;
	default:
		cout << "\n\n������������ �����!!!\n����������, �������� ����� �� 1 �� 6.\n\n";
		system("pause");
		break;
	}
}

void StringInstrument::SaveToFile(std::ofstream& outputFile) {
	outputFile << "�����: " << GetNumberInstrument() << "\n"
			   << "�������� ����������\n\n"
			   << "��������: " << GetNameInstrument() << "\n"
			   << "��� ���������: " << GetFullNameOwner() << "\n"
			   << "���������� ������ � ��������: " << GetNumUnitsOrchestra() << "\n"
			   << "���������: " << GetCost() << "\n"
			   << "�������������: " << NameManufacture << "\n"
			   << "��������: " << TextDescription << "\n\n\n";
}

void StringInstrument::SaveSpecial(std::ofstream& fout) {
	fout << "S" << endl
		 << GetNameInstrument() << endl
		 << GetFullNameOwner() << endl
		 << GetNumUnitsOrchestra() << endl
		 << GetCost() << endl
		 << NameManufacture << endl
		 << TextDescription << endl;
}

void StringInstrument::LoadFile(std::ifstream& fin) {
	for (int i = 0; i < 6; i++) {
		switch (i) {
		case 0:
			SetNameInstrument(readLineFile(fin));
			break;
		case 1:
			SetFullNameOwner(readLineFile(fin));
			break;
		case 2:
			SetNumUnitsOrchestra(atoi(readLineFile(fin)));
			break;
		case 3:
			SetCost(convertToFloat(readLineFile(fin)));  
			break;
		case 4:
			NameManufacture = readLineFile(fin); 
			break;
		case 5:
			TextDescription = readLineFile(fin); 
			break;
		}
	}
}