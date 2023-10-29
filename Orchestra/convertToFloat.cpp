#include "convertToFloat.h"


float convertToFloat(const char* str) {
    char* end;
    setlocale(LC_NUMERIC, "en_US.utf8"); // Установка локали с плавающей точкой в формате US
    float result = strtof(str, &end);
    return result;
}