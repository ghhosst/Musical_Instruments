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
	std::cout << "\n\nВВВУУУУУУУ\n\n";
}