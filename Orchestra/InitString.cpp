#define _CRT_SECURE_NO_WARNINGS 
#include "initString.h"
#include <iostream>

char* initString(char* s) {

    const char* initStr = "\t-";
    s = new char[2];
    strcpy(s, initStr);

    return s;
}
