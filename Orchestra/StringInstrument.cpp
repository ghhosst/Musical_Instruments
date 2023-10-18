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
	std::cout << "\n\nДзиинннннннь\n\n";
}