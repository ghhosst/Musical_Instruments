#include "PercussionInstrument.h"
using std::cout;
using std::cin;		
using std::endl;

PercussionInstrument::PercussionInstrument() {
	int choicePercussionInst;
	int NumUnitsPercussion, CostPercussion;
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
			TypeInstrument = getString(&lenString);
			break;
		case 6:
			break;
		default:
			break;
		}
	} while (choicePercussionInst != 6);
}

char* PercussionInstrument::GetTypeInstrument() {
	return this->TypeInstrument;
}

void PercussionInstrument::SetTypeInstrument(char* TypeInstrument) {
	this->TypeInstrument = TypeInstrument;
}

void PercussionInstrument::Sound() {
	std::cout << "\n\nБУМММММММ...\n\n";
}