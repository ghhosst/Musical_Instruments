#include "Keeper.h"
using std::cout, std::cin, std::endl; 

Keeper::Keeper() {
	system("cls");
	std::cout << "\n----|Вызван конструктор класса Keeper (без параметров)|----\n";
	system("pause");

	root = nullptr;
	rear = nullptr;
	index = nullptr;
}

Keeper::Keeper(Element* root, Element* rear, Element* index) {
	std::cout << "\n----|Вызван конструктор класса Keeper (с параметрами)|----\n";
	system("pause");

	this->root = root;
	this->rear = rear;
	this->index = index; 
}

Keeper::Keeper(const Keeper& other) {
	std::cout << "\n----|Вызван конструктор класса Keeper (копирования)|----\n";
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
	std::cout << "\n----|Вызван деструктор класса Keeper|----\n";
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

void Keeper::Add() {
m1:
	int choiceInstrument;
	system("cls");
	cout << "Какой инструмент добавить в оркестр ?" << endl
		<< "1) Ударный" << endl
		<< "2) Струнный" << endl
		<< "3) Духовой" << endl
		<< "Выбранный пункт: ";
	cin >> choiceInstrument;

	if ((choiceInstrument != 1) && (choiceInstrument != 2) && (choiceInstrument != 3)) {
		cout << "\n\nНеккоректный выбор!!!\nПожалуйста, выберете пункт меню от 1 до 3.\n\n";
		system("pause");
		goto m1;
	}

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
}

void Keeper::ShowOrchestra() {
	system("cls");
	while (index != nullptr) {
		cout << "\n\nНомер: " << index->GetNumberElement();
		(index->GetInstrument())->ShowInstrument();
		index = index->GetNext();
	}
	index = root;
	cout << "\n\n";
	system("pause");
}

void Keeper::DeleteInstrument() {
	int cnt = 1;
	int choiceDelete;
	ShowOrchestra();
	cout << "\n\n\nВведите номер инструмента, который хотите удалить: ";
	cin >> choiceDelete;

	if ((choiceDelete <= 0) || (choiceDelete > rear->GetNumberElement())) {
		cout << "\n\nНеккоректный выбор!!!\nИнструмента с таким номером нет в оркестре.\n\n";
		system("pause");
		return;
	}

	while (index->GetNumberElement() != choiceDelete){
		index = index->GetNext();
	}

	if (root == rear) {
		root = nullptr;
		rear = nullptr;
		delete index;
		index = nullptr;
		return;
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

void Keeper::СhangeInstrument(){
	int choiceChange;
	ShowOrchestra();
	cout << "\n\nВведите номер инструмента, данные которого вы хотите изменить: ";
	cin >> choiceChange;

	if ((choiceChange <= 0) || (choiceChange > rear->GetNumberElement())) {
		cout << "\n\nНеккоректный выбор!!!\nИнструмента с таким номером нет в оркестре.\n\n"; 
		system("pause");  
		return; 
	}

	system("cls");

	while (index->GetNumberElement() != choiceChange) {
		index = index->GetNext(); 
	}
	(index->GetInstrument())->ShowInstrument();
	(index->GetInstrument())->Change();
	index = root;
}

void Keeper::Save() {
	std::ofstream outputFile;
	outputFile.open("Orchestra.txt");
	if (outputFile.is_open()) {
		while (index != nullptr) {
			(index->GetInstrument())->SaveToFile(outputFile);
			index = index->GetNext(); 
		}
		index = root;
		cout << "\n\nОркестр успешно сохранён в файл !!!\n\n";
		system("pause");
	}
	else {
		system("cls");
		cout << "\n\nОшибка!!!\nФайл открыть не удалось.\n\n";
		system("pause"); 
	}	
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
	else {
		system("cls");
		cout << "\n\nОшибка!!!\nФайл открыть не удалось.\n\n";
		system("pause");
	}
	fout.close();
	
}

void Keeper::Load() {
	std::ifstream fin;
	fin.open("special.txt"); 
	if (fin.is_open()) {
		while (!fin.eof()) {
			Element* element = nullptr;
			char* line = readLineFile(fin);

			if (!strcmp(line, "P")) {
				element = new Element('P');
				(element->GetInstrument())->LoadFile(fin);
			}
			if (!strcmp(line, "S")) {
				element = new Element('S');
				(element->GetInstrument())->LoadFile(fin); 
			}
			if (!strcmp(line, "W")) {
				element = new Element('W');
				(element->GetInstrument())->LoadFile(fin); 
			}
			if (*line == '\0')
				return;

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
	else {
		system("cls");
		cout << "\n\nОшибка!!!\nФайл открыть не удалось.\n\n";
		system("pause");
	}

	fin.close();
}