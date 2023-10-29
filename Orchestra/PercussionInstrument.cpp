#define _CRT_SECURE_NO_WARNINGS  
#include "PercussionInstrument.h"
using std::cout, std::cin, std::endl;

PercussionInstrument::PercussionInstrument() {
	std::cout << "\n----|������ ����������� ������ PercussionInstrument (��� ����������)|----\n";
	system("pause");

	const char* initStr = "\t-";
	
	TypePerc = new char[sizeof(initStr)]; 
	strcpy(TypePerc, initStr);  

	int choicePercussionInst;
	int NumUnitsPercussion;
	float CostPercussion;
	int lenString;
	do {
		system("cls");
		cout << "������� ������ �� ������� �����������" << endl
			<< "1) ��������" << endl
			<< "2) ��� ���������" << endl
			<< "3) ���������� ������ � ��������" << endl
			<< "4) ���������" << endl
			<< "5) ���" << endl
			<< "6) �����" << endl
			<< "��������� �����: ";
		cin >> choicePercussionInst;


		switch (choicePercussionInst) {
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
			cin >> NumUnitsPercussion;
			SetNumUnitsOrchestra(NumUnitsPercussion);
			break;
		case 4:
			system("cls");
			cout << "������� ����������\n";
			cout << "������� ���������: ";
			cin >> CostPercussion;
			SetCost(CostPercussion);
			break;
		case 5:
			system("cls");
			cout << "������� ����������\n";
			cout << "������� ���: \n" << endl;
			TypePerc = getString(&lenString);
			break;
		case 6:
			break;
		default:
			cout << "\n\n������������ �����!!!\n����������, �������� ����� �� 1 �� 6.\n\n";
			system("pause");
			break;
		}
	} while (choicePercussionInst != 6);
}

PercussionInstrument::PercussionInstrument(char file) {
	std::cout << "\n----|������ ����������� ������ PercussionInstrument (� ����������)|----\n";
	system("pause");

	TypePerc = nullptr;
}

PercussionInstrument::PercussionInstrument(const PercussionInstrument& other) {
	std::cout << "\n----|������ ����������� ������ PercussionInstrument (�����������)|----\n";
	system("pause");

	strcpy(this->TypePerc, other.TypePerc);
}

PercussionInstrument::~PercussionInstrument() {
	std::cout << "\n----|������ ���������� ������ PercussionInstrument|----\n";
	system("pause");

	delete[] TypePerc; 
	TypePerc = nullptr;
}

char* PercussionInstrument::GetTypePerc() {
	return this->TypePerc;
}

void PercussionInstrument::SetTypePerc(char* TypeInstrument) {
	this->TypePerc = TypeInstrument;
}

void PercussionInstrument::ShowInstrument() {
	cout << "\n������� ����������\n\n"
		<< "��������: " << GetNameInstrument() << endl
		<< "��� ���������: " << GetFullNameOwner() << endl
		<< "���������� ������ � ��������: " << GetNumUnitsOrchestra() << endl
		<< "���������: " << GetCost() << endl
		<< "���: " << GetTypePerc() << endl;
}

void PercussionInstrument::Change() {
	int lenString;
	int choiceChangePerc;
	int NumUnitsPercussion;
	float CostPercussion; 
	cout << "\n\n�������� �����, ������� ������ ��������..." << endl
		<< "1) ��������" << endl
		<< "2) ��� ���������" << endl
		<< "3) ���������� ������ � ��������" << endl
		<< "4) ���������" << endl
		<< "5) ���" << endl
		<< "��������� �����: ";
	cin >> choiceChangePerc;
	switch (choiceChangePerc){
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
		cout << "������� ���: ";
		TypePerc = getString(&lenString);
		break;
	default:
		cout << "\n\n������������ �����!!!\n����������, �������� ����� �� 1 �� 5.\n\n";
		system("pause"); 
		break;
	}
}

void PercussionInstrument::SaveToFile(std::ofstream& outputFile) {
	outputFile << "�����: " << GetNumberInstrument() << "\n"
			   << "������� ����������\n\n"
			   << "��������: " << GetNameInstrument() << "\n"
			   << "��� ���������: " << GetFullNameOwner() << "\n"
			   << "���������� ������ � ��������: " << GetNumUnitsOrchestra() << "\n"
			   << "���������: " << GetCost() << "\n"
			   << "���: " << TypePerc << "\n\n\n";
}

void PercussionInstrument::SaveSpecial(std::ofstream& fout) {
	fout << "P" << endl 
		 << GetNameInstrument() << endl 
		 << GetFullNameOwner() << endl 
	 	 << GetNumUnitsOrchestra() << endl 
		 << GetCost() << endl 
		 << TypePerc << endl;  
}

void PercussionInstrument::LoadFile(std::ifstream& fin) { 
	for (int i = 0; i < 5; i++) {
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
			TypePerc = readLineFile(fin);
			break;
		}
	}
}