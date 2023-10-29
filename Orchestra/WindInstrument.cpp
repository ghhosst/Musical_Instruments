#define _CRT_SECURE_NO_WARNINGS    
#include "WindInstrument.h"
using std::cout;
using std::cin;
using std::endl;

WindInstrument::WindInstrument() {
	std::cout << "\n----|Вызван конструктор класса WindInstrument (без параметров)|----\n";
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
		cout << "Введите данные о духовом инструменте" << endl
			<< "1) Название" << endl
			<< "2) ФИО владельца" << endl
			<< "3) Количество единиц в оркестре" << endl
			<< "4) Стоимость" << endl
			<< "5) Наименование производителя" << endl
			<< "6) Какие дефекты присутвсвуют" << endl
			<< "7) Выход" << endl
			<< "Выбранный пункт: ";
		cin >> choiceWind;


		switch (choiceWind) {
		case 1:
			system("cls");
			cout << "Духовой интрумент\n";
			cout << "Введите название:\n" << endl;
			SetNameInstrument(getString(&lenString));
			break;
		case 2:
			system("cls");
			cout << "Духовой инструмент\n";
			cout << "Введите ФИО владельца:\n" << endl;
			SetFullNameOwner(getString(&lenString));
			break;
		case 3:
			system("cls");
			cout << "Духовой инструмент\n";
			cout << "Введите количество единиц в оркестре: ";
			cin >> NumUnitsWind;
			SetNumUnitsOrchestra(NumUnitsWind);
			break;
		case 4:
			system("cls");
			cout << "Духовой инструмент\n";
			cout << "Введите стоимость: ";
			cin >> CostWind;
			SetCost(CostWind);
			break;
		case 5:
			system("cls");
			cout << "Духовой инструмент\n";
			cout << "Введите наименование производителя: \n" << endl;
			NameManufacture = getString(&lenString);
			break;
		case 6:
			system("cls");
			cout << "Духовой инструмент\n";
			cout << "Напишите какие дефекты присутсвуют в этом инструменте:\n" << endl;
			Defects = getString(&lenString);
			break;
		case 7:
			break;
		default:
			cout << "\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт от 1 до 7.\n\n";
			system("pause");
			break;
		}
	} while (choiceWind != 7);
}

WindInstrument::WindInstrument(char file) { 
	std::cout << "\n----|Вызван конструктор класса WindInstrument (с параметром)|----\n";
	system("pause");

	NameManufacture = nullptr;
	Defects = nullptr; 
}

WindInstrument::WindInstrument(const WindInstrument& other) {
	std::cout << "\n----|Вызван конструктор класса WindInstrument (копирования)|----\n";
	system("pause");
	strcpy(this->NameManufacture, other.NameManufacture);
	strcpy(this->Defects, other.Defects);
}

WindInstrument::~WindInstrument() {
	std::cout << "\n----|Вызван деструктор класса WindInstrument|----\n";
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
	cout << "\nУдарный инструмент\n\n"
		<< "Название: " << GetNameInstrument() << endl
		<< "ФИО владельца: " << GetFullNameOwner() << endl
		<< "Количество единиц в оркестре: " << GetNumUnitsOrchestra() << endl
		<< "Стоимость: " << GetCost() << endl
		<< "Наименование производителя: " << GetNameManufacture() << endl
		<< "Дефекты: " << GetDefects() << endl;
}

void WindInstrument::Change() {
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
		cout << "Напишите какие дефекты присутсвуют в этом инструменте: ";
		Defects = getString(&lenString);
		break;
	default:
		cout << "\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт от 1 до 6.\n\n";
		system("pause"); 
		break;
	}
}

void WindInstrument::SaveToFile(std::ofstream& outputFile) {
	outputFile << "Номер: " << GetNumberInstrument() << "\n"
			   << "Духовой инструмент\n\n"
			   << "Название: " << GetNameInstrument() << "\n"
			   << "ФИО владельца: " << GetFullNameOwner() << "\n"
			   << "Количество единиц в оркестре: " << GetNumUnitsOrchestra() << "\n"
			   << "Стоимость: " << GetCost() << "\n"
			   << "Производитель: " << NameManufacture << "\n"
			   << "Дефекты: " << Defects << "\n\n\n";
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