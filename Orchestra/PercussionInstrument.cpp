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
	std::cout << "\n\n���������...\n\n";
}