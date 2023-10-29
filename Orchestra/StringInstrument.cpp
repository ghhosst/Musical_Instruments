#define _CRT_SECURE_NO_WARNINGS  
#include "StringInstrument.h"
using std::cout; 
using std::cin; 
using std::endl;

StringInstrument::StringInstrument() {
	std::cout << "\n----|Вызван конструктор класса StringInstrument (без параметров)|----\n";
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
		cout << "Введите данные о струнном инструменте" << endl
			<< "1) Название" << endl
			<< "2) ФИО владельца" << endl
			<< "3) Количество единиц в оркестре" << endl
			<< "4) Стоимость" << endl
			<< "5) Наименование производителя" << endl
			<< "6) Краткое текстовое описание" << endl
			<< "7) Выход" << endl
			<< "Выбранный пункт: ";
		cin >> choiceStringInst;


		switch (choiceStringInst) {
		case 1:
			system("cls");
			cout << "Струнный интрумент\n";
			cout << "Введите название:\n" << endl;
			SetNameInstrument(getString(&lenString));
			break;
		case 2:
			system("cls");
			cout << "Струнный инструмент\n";
			cout << "Введите ФИО владельца:\n" << endl;
			SetFullNameOwner(getString(&lenString));
			break;
		case 3:
			system("cls");
			cout << "Струнный инструмент\n";
			cout << "Введите количество единиц в оркестре: ";
			cin >> NumUnitsStringInst;
			SetNumUnitsOrchestra(NumUnitsStringInst);
			break;
		case 4:
			system("cls");
			cout << "Струнный инструмент\n";
			cout << "Введите стоимость: ";
			cin >> CostStringInst;
			SetCost(CostStringInst);
			break;
		case 5:
			system("cls");
			cout << "Струнный инструмент\n";
			cout << "Введите наименование производителя: \n" << endl;
			NameManufacture = getString(&lenString);
			break;
		case 6:
			system("cls");
			cout << "Струнный инструмент\n";
			cout << "Напишите краткое текстовое описание:\n" << endl;
			TextDescription = getString(&lenString);
			break;
		case 7:
			break;
		default:
			cout << "\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт от 1 до 7.\n\n";
			system("pause");
			break;
		}
	} while (choiceStringInst != 7);
}

StringInstrument::StringInstrument(char file) { 
	std::cout << "\n----|Вызван конструктор класса StringInstrument (с параметром)|----\n";
	system("pause");

	NameManufacture = nullptr;
	TextDescription = nullptr;
}

StringInstrument::StringInstrument(const StringInstrument& other) {
	std::cout << "\n----|Вызван конструктор класса StringInstrument (копирования)|----\n";
	system("pause");

	strcpy(this->NameManufacture, other.NameManufacture);
	strcpy(this->TextDescription, other.TextDescription);
}

StringInstrument::~StringInstrument() {
	std::cout << "\n----|Вызван деструктор класса StringInstrument|----\n";
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
	cout << "\nСтрунный инструмент\n\n"
		<< "Название: " << GetNameInstrument() << endl
		<< "ФИО владельца: " << GetFullNameOwner() << endl
		<< "Количество единиц в оркестре: " << GetNumUnitsOrchestra() << endl
		<< "Стоимость: " << GetCost() << endl
		<< "Производитель: " << GetNameManufacture() << endl
		<< "Описание: " << GetTextDescription() << endl;
}

void StringInstrument::Change() {
	int lenString;
	int choiceChangePerc;
	int NumUnitsPercussion;
	float CostPercussion;
	cout << "\n\nВыберете пункт, который хотите изменить..." << endl
		<< "1) Название" << endl
		<< "2) ФИО владельца" << endl
		<< "3) Количество единиц в оркестре" << endl
		<< "4) Стоимость" << endl
		<< "5) Производитель" << endl
		<< "6) Описание" << endl
		<< "Выбранный пункт: ";
	cin >> choiceChangePerc;
	switch (choiceChangePerc) {
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
		cout << "Введите наименование производителя: ";
		NameManufacture = getString(&lenString); 
		break;
	case 6:
		cout << "Напишите краткое текстовое описание: ";
		TextDescription = getString(&lenString);
		break;
	default:
		cout << "\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт от 1 до 6.\n\n";
		system("pause");
		break;
	}
}

void StringInstrument::SaveToFile(std::ofstream& outputFile) {
	outputFile << "Номер: " << GetNumberInstrument() << "\n"
			   << "Струнный инструмент\n\n"
			   << "Название: " << GetNameInstrument() << "\n"
			   << "ФИО владельца: " << GetFullNameOwner() << "\n"
			   << "Количество единиц в оркестре: " << GetNumUnitsOrchestra() << "\n"
			   << "Стоимость: " << GetCost() << "\n"
			   << "Производитель: " << NameManufacture << "\n"
			   << "Описание: " << TextDescription << "\n\n\n";
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