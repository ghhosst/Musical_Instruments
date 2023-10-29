#define _CRT_SECURE_NO_WARNINGS    
#include "WindInstrument.h"
using std::cout;
using std::cin;
using std::endl;

WindInstrument::WindInstrument() {
	std::cout << "\n----|������ ����������� ������ WindInstrument (��� ����������)|----\n";
	system("pause");

	const char* initStr = "\t-";
	
	NameManufacture = new char[sizeof(initStr)]; 
	strcpy(NameManufacture, initStr);

	Defects = new char[sizeof(initStr)]; 
	strcpy(Defects, initStr); 

	int choiceWind;
	int NumUnitsWind;
	float CostWind;
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
			cout << "\n\n������������ �����!!!\n����������, �������� ����� �� 1 �� 7.\n\n";
			system("pause");
			break;
		}
	} while (choiceWind != 7);
}

WindInstrument::WindInstrument(char file) { 
	std::cout << "\n----|������ ����������� ������ WindInstrument (� ����������)|----\n";
	system("pause");

	NameManufacture = nullptr;
	Defects = nullptr; 
}

WindInstrument::WindInstrument(const WindInstrument& other) {
	std::cout << "\n----|������ ����������� ������ WindInstrument (�����������)|----\n";
	system("pause");
	strcpy(this->NameManufacture, other.NameManufacture);
	strcpy(this->Defects, other.Defects);
}

WindInstrument::~WindInstrument() {
	std::cout << "\n----|������ ���������� ������ WindInstrument|----\n";
	system("pause");
	delete[] NameManufacture;
	NameManufacture = nullptr;
	delete[] Defects;
	Defects = nullptr;
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

void WindInstrument::ShowInstrument() {
	cout << "\n������� ����������\n\n"
		<< "��������: " << GetNameInstrument() << endl
		<< "��� ���������: " << GetFullNameOwner() << endl
		<< "���������� ������ � ��������: " << GetNumUnitsOrchestra() << endl
		<< "���������: " << GetCost() << endl
		<< "������������ �������������: " << GetNameManufacture() << endl
		<< "�������: " << GetDefects() << endl;
}

void WindInstrument::Change() {
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
		cout << "�������� ����� ������� ����������� � ���� �����������: ";
		Defects = getString(&lenString);
		break;
	default:
		cout << "\n\n������������ �����!!!\n����������, �������� ����� �� 1 �� 6.\n\n";
		system("pause"); 
		break;
	}
}

void WindInstrument::SaveToFile(std::ofstream& outputFile) {
	outputFile << "�����: " << GetNumberInstrument() << "\n"
			   << "������� ����������\n\n"
			   << "��������: " << GetNameInstrument() << "\n"
			   << "��� ���������: " << GetFullNameOwner() << "\n"
			   << "���������� ������ � ��������: " << GetNumUnitsOrchestra() << "\n"
			   << "���������: " << GetCost() << "\n"
			   << "�������������: " << NameManufacture << "\n"
			   << "�������: " << Defects << "\n\n\n";
}

void WindInstrument::SaveSpecial(std::ofstream& fout) {
	fout << "W" << endl
		 << GetNameInstrument() << endl
		 << GetFullNameOwner() << endl
		 << GetNumUnitsOrchestra() << endl
		 << GetCost() << endl
		 << NameManufacture << endl
		 << Defects << endl;
}

void WindInstrument::LoadFile(std::ifstream& fin) {
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
			Defects = readLineFile(fin);
			break;
		}
	}
}