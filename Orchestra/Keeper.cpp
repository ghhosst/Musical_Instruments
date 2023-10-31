#include "Keeper.h"
using std::cout, std::cin, std::endl; 

Keeper::Keeper() {
	system("cls");
	std::cout << "\n----|������ ����������� ������ Keeper (��� ����������)|----\n";
	system("pause");

	root = nullptr;
	rear = nullptr;
	index = nullptr;
}

Keeper::Keeper(Element* root, Element* rear, Element* index) {
	std::cout << "\n----|������ ����������� ������ Keeper (� �����������)|----\n";
	system("pause");

	this->root = root;
	this->rear = rear;
	this->index = index; 
}

Keeper::Keeper(const Keeper& other) {
	std::cout << "\n----|������ ����������� ������ Keeper (�����������)|----\n";
	system("pause");

	this->root = nullptr;
	this->rear = nullptr;
	this->index = nullptr;

	if (other.rear == nullptr)
		return;

	Element* firstElement = new Element(other.root->GetTypeInstrument()); 
	this->root = firstElement; 
	Element* newRear_tmp = firstElement; 

	Element* rear_tmp = other.root->GetNext();
	while (rear_tmp != nullptr) { 
		Element* element = new Element(rear_tmp->GetTypeInstrument()); 
		this->rear = element; 
		element->SetPrev(newRear_tmp); 
		newRear_tmp->SetNext(element); 
		newRear_tmp = newRear_tmp->GetNext();  

		rear_tmp = rear_tmp->GetNext();  
	}

	this->index = this->root;
}

Keeper::~Keeper() {
	std::cout << "\n----|������ ���������� ������ Keeper|----\n";
	system("pause");

	while (index != nullptr) {
		if (index == nullptr) {
			return;
		}

		if (index == rear) {
			delete rear;
			index = nullptr;
			rear = nullptr;
			root = nullptr;
			return;
		}

		Element* tmp_element = index;
		index = tmp_element->GetNext();
		delete tmp_element; 
	}
}

Element* Keeper::GetRoot() {
	return root;
}

void Keeper::SetRoot(Element* root) {
	this->root = root;
}

Element* Keeper::GetRear() {
	return rear;
} 

void Keeper::SetRear(Element* rear) {
	this->rear = rear;
}

Element* Keeper::GetIndex() { 
	return index;
}

void Keeper::SetIndex(Element* index) {
	this->index = index;
}
 
Keeper& Keeper::operator++() {  
	int choiceInstrument;
	system("cls");
	cout << "����� ���������� �������� � ������� ?" << endl
		<< "1) �������" << endl
		<< "2) ��������" << endl
		<< "3) �������" << endl
		<< "��������� �����: ";
	cin >> choiceInstrument;

	if ((choiceInstrument != 1) && (choiceInstrument != 2) && (choiceInstrument != 3))
		throw MyException("\n\n������������ �����!!!\n����������, �������� ����� ���� �� 1 �� 3.\n\n");

	Element* element = new Element(choiceInstrument);

	element->SetPrev(rear);
	if (root == nullptr) { // list empty
		root = element;
		index = element;
	}
	if (rear != nullptr)
		rear->SetNext(element);
	rear = element;

	if (element->GetPrev() != nullptr) {
		element->SetNumberElement((element->GetPrev())->GetNumberElement() + 1);
		(element->GetInstrument())->SetNumberInstrument((element->GetPrev())->GetNumberElement() + 1);
	}
	else {
		element->SetNumberElement(1);
		(element->GetInstrument())->SetNumberInstrument(1);
	}
	return *this; 
}

void Keeper::ShowOrchestra() {
	try {
		if (rear == nullptr)
			throw MyException();

		system("cls");
		while (index != nullptr) {
			cout << "\n\n�����: " << index->GetNumberElement();
			(index->GetInstrument())->ShowInstrument();
			index = index->GetNext();
		}
		index = root;
		cout << "\n\n";
		system("pause");
	}
	catch (MyException& ex) {
		ex.GetNumError();
		system("pause");
	}
}

Keeper& Keeper::operator --() {
	try {
		if (rear == nullptr)
			throw MyException();

		int cnt = 1;
		int choiceDelete;
		ShowOrchestra();
		cout << "\n\n\n������� ����� �����������, ������� ������ �������: ";
		cin >> choiceDelete;

		if ((choiceDelete <= 0) || (choiceDelete > rear->GetNumberElement()))
			throw MyException("\n\n������������ �����!!!\n����������� � ����� ������� ��� � ��������.\n\n");

		while (index->GetNumberElement() != choiceDelete) {
			index = index->GetNext();
		}

		if (root == rear) {
			root = nullptr;
			rear = nullptr;
			delete index;
			index = nullptr;
			return *this;
		}
		else {
			if (index == rear) {
				rear = index->GetPrev();
				rear->SetNext(nullptr);
				delete index;
				index = root;
			}
			else {
				if (index == root) {
					root = index->GetNext();
					root->SetPrev(nullptr);
					delete index;
					index = root;
				}
				else {
					(index->GetPrev())->SetNext(index->GetNext());
					(index->GetNext())->SetPrev(index->GetPrev());
					delete index;
					index = root;

				}
			}

		}

		while (index != nullptr) {
			index->SetNumberElement(cnt);
			index = index->GetNext();
			cnt++;
		}
		index = root;
	}
	catch (MyException& ex){
		ex.GetNumError();
		system("pause");
	}
	return *this; 
}

void Keeper::�hangeInstrument(){
	try {
		if (rear == nullptr)
			throw MyException();

		int choiceChange;
		ShowOrchestra();
		cout << "\n\n������� ����� �����������, ������ �������� �� ������ ��������: ";
		cin >> choiceChange;

		if ((choiceChange <= 0) || (choiceChange > rear->GetNumberElement()))
			throw MyException("\n\n������������ �����!!!\n����������� � ����� ������� ��� � ��������.\n\n");

		system("cls");

		while (index->GetNumberElement() != choiceChange) {
			index = index->GetNext();
		}
		(index->GetInstrument())->ShowInstrument();
		(index->GetInstrument())->Change();
		index = root;
	}
	catch (MyException& ex){
		ex.GetNumError();
		system("pause");
	}
}

void Keeper::Save() {

	int chClear = 0;

	try {
		if (root == nullptr) {
			throw MyException();
		}
	}
	catch (MyException& ex) { 
		ex.GetNumError();
		cout << "\n�������� ���� ?" << endl
			 << "1) ��" << endl
			 << "2) ���" << endl
			 << "��������� �����: ";
		cin >> chClear;
		if (chClear == 2)
			return;
		if (chClear == 1)
			goto m1;
		if (chClear != 1 && chClear != 2)
			throw MyException("\n\n������������ ����� !!!\n����������, �������� ����� ���� �� 1 �� 2.\n\n");
	}
m1:
	std::ofstream outputFile;
	outputFile.open("Orchestra.txt");
	if (outputFile.is_open()) {
		while (index != nullptr) {
			(index->GetInstrument())->SaveToFile(outputFile);
			index = index->GetNext(); 
		}
		index = root;
		if (chClear != 1) {
			cout << "\n\n������� ������� ������� � ���� !!!\n\n";
			system("pause");
		}
		if (chClear == 1) {
			cout << "\n\n���� ������ !!!\n\n";
			system("pause");
		}
	}
	else 
		throw MyException("\n\n������!!!\n���� ������� �� �������.\n\n");
	
	outputFile.close(); 


	std::ofstream fout;
	fout.open("special.txt");
	if (fout.is_open()) {
		while (index != nullptr) {
			(index->GetInstrument())->SaveSpecial(fout);
			index = index->GetNext();
		}
		index = root;
	}
	else 
		throw MyException("\n\n������!!!\n���� ������� �� �������.\n\n");
	
	fout.close();
	
}

void Keeper::Load() {
	bool flag = false;
	std::ifstream fin;
	fin.open("special.txt"); 
	if (fin.is_open()) {
		while (!fin.eof()) {
			Element* element = nullptr;
			char* line = readLineFile(fin);

			if (!strcmp(line, "P")) {
				flag = true;
				element = new Element('P');
				(element->GetInstrument())->LoadFile(fin);
			}
			if (!strcmp(line, "S")) {
				flag = true;
				element = new Element('S');
				(element->GetInstrument())->LoadFile(fin); 
			}
			if (!strcmp(line, "W")) {
				flag = true;
				element = new Element('W');
				(element->GetInstrument())->LoadFile(fin); 
			}

			if (*line == '\0') {
				delete[] line;
				if (!flag)
					throw MyException("\n\n���� ����!!!\n��������� ������� �� �������.\n\n");
				return;
			}

			delete[] line;

			element->SetPrev(rear);
			if (root == nullptr) { // list empty
				root = element;
				index = element;
			}
			if (rear != nullptr)
				rear->SetNext(element);
			rear = element;


			if (element->GetPrev() != nullptr) { 
				element->SetNumberElement((element->GetPrev())->GetNumberElement() + 1); 
				(element->GetInstrument())->SetNumberInstrument((element->GetPrev())->GetNumberElement() + 1); 
			} 
			else { 
				element->SetNumberElement(1); 
				(element->GetInstrument())->SetNumberInstrument(1); 
			}
		}
	}
	else
		throw MyException("\n\n������!!!\n���� ������� �� �������.\n\n");

	fin.close();
}