#define _CRT_SECURE_NO_WARNINGS  
#include "PercussionInstrument.h"
using std::cout, std::cin, std::endl;

PercussionInstrument::PercussionInstrument() {
	std::cout << "\n----|Вызван конструктор класса PercussionInstrument (без параметров)|----\n";
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
		cout << "Введите данные об ударном инструменте" << endl
			<< "1) Название" << endl
			<< "2) ФИО владельца" << endl
			<< "3) Количество единиц в оркестре" << endl
			<< "4) Стоимость" << endl
			<< "5) Тип" << endl
			<< "6) Выход" << endl
			<< "Выбранный пункт: ";
		cin >> choicePercussionInst;


		switch (choicePercussionInst) {
		case 1:
			system("cls");
			cout << "Ударный интрумент\n";
			cout << "Введите название:\n" << endl;
			SetNameInstrument(getString(&lenString));
			break;
		case 2:
			system("cls");
			cout << "Ударный инструмент\n";
			cout << "Введите ФИО владельца:\n" << endl;
			SetFullNameOwner(getString(&lenString));
			break;
		case 3:
			system("cls");
			cout << "Ударный инструмент\n";
			cout << "Введите количество единиц в оркестре: ";
			cin >> NumUnitsPercussion;
			SetNumUnitsOrchestra(NumUnitsPercussion);
			break;
		case 4:
			system("cls");
			cout << "Ударный инструмент\n";
			cout << "Введите стоимость: ";
			cin >> CostPercussion;
			SetCost(CostPercussion);
			break;
		case 5:
			system("cls");
			cout << "Ударный инструмент\n";
			cout << "Введите тип: \n" << endl;
			TypePerc = getString(&lenString);
			break;
		case 6:
			break;
		default:
			cout << "\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт от 1 до 6.\n\n";
			system("pause");
			break;
		}
	} while (choicePercussionInst != 6);
}

PercussionInstrument::PercussionInstrument(char file) {
	std::cout << "\n----|Вызван конструктор класса PercussionInstrument (с параметром)|----\n";
	system("pause");

	TypePerc = nullptr;
}

PercussionInstrument::PercussionInstrument(const PercussionInstrument& other) {
	std::cout << "\n----|Вызван конструктор класса PercussionInstrument (копирования)|----\n";
	system("pause");

	strcpy(this->TypePerc, other.TypePerc);
}

PercussionInstrument::~PercussionInstrument() {
	std::cout << "\n----|Вызван деструктор класса PercussionInstrument|----\n";
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
	cout << "\nУдарный инструмент\n\n"
		<< "Название: " << GetNameInstrument() << endl
		<< "ФИО владельца: " << GetFullNameOwner() << endl
		<< "Количество единиц в оркестре: " << GetNumUnitsOrchestra() << endl
		<< "Стоимость: " << GetCost() << endl
		<< "Тип: " << GetTypePerc() << endl;
}

void PercussionInstrument::Change() {
	int lenString;
	int choiceChangePerc;
	int NumUnitsPercussion;
	float CostPercussion; 
	cout << "\n\nВыберете пункт, который хотите изменить..." << endl
		<< "1) Название" << endl
		<< "2) ФИО владельца" << endl
		<< "3) Количество единиц в оркестре" << endl
		<< "4) Стоимость" << endl
		<< "5) Тип" << endl
		<< "Выбранный пункт: ";
	cin >> choiceChangePerc;
	switch (choiceChangePerc){
	case 1:
		cout << "\nВведите название: ";
		SetNameInstrument(getString(&lenString));
		break;
	case 2:
		cout << "\nВведите ФИО владельца: ";
		SetFullNameOwner(getString(&lenString));
		break;
	case 3:
		cout << "Введите количество единиц в оркестре: ";
		cin >> NumUnitsPercussion;
		SetNumUnitsOrchestra(NumUnitsPercussion);
		break;
	case 4:
		cout << "Введите стоимость: ";
		cin >> CostPercussion;
		SetCost(CostPercussion);
		break;
	case 5:
		cout << "Введите тип: ";
		TypePerc = getString(&lenString);
		break;
	default:
		cout << "\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт от 1 до 5.\n\n";
		system("pause"); 
		break;
	}
}

void PercussionInstrument::SaveToFile(std::ofstream& outputFile) {
	outputFile << "Номер: " << GetNumberInstrument() << "\n"
			   << "Ударный инструмент\n\n"
			   << "Название: " << GetNameInstrument() << "\n"
			   << "ФИО владельца: " << GetFullNameOwner() << "\n"
			   << "Количество единиц в оркестре: " << GetNumUnitsOrchestra() << "\n"
			   << "Стоимость: " << GetCost() << "\n"
			   << "Тип: " << TypePerc << "\n\n\n";
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