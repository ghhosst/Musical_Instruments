#include "MyException.h"


MyException::MyException() {
	NumError = 1;
	std::cout << "\n\nВ оркестре нет ни одного инструмента!!!";
}

void MyException::GetNumError() { std::cout << "\nКод ошибки: " << NumError << "\n\n"; };