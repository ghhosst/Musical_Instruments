#include "String.h"
#include <cstdio> 

char* String::getString(int* len) {
    bool flag = true;
    *len = 0;           // initially the line is empty
    int capacity = 1;   // capacity of the dynamic string container (1, so how exactly will it be '\0')

    char* s = new char[1];
    char* sPtr = s;
m1:
    char c = getchar(); // symbol for reading data
    if ((*len == 0) && (flag)) {
        flag = false;
        goto m1;
    }

    // we read the characters until we get a line break character (\n)
    while (c != '\n') {
        s[(*len)++] = c; // adding a new character to the string

        // if the actual size is larger than the size of the container, then we will increase its size
        if (*len >= capacity) {
            char* tmp = new char[*len];
            char* tmpPtr = tmp;
            for (int i = 0; i < *len; i++) {
                *tmpPtr = *sPtr;
                sPtr++;
                tmpPtr++;
            }
            delete s;
            capacity *= 2;          // we double the capacity of the string
            s = new char[capacity]; // creating a new row with increased capacity  
            sPtr = s;
            tmpPtr = tmp;
            for (int i = 0; i < capacity; i++) {
                *sPtr = *tmpPtr;
                tmpPtr++;
                sPtr++;
            }
            delete tmp;
            sPtr = s;
        }
        c = getchar();  // read the following character         
    }

    s[*len] = '\0';     // we end the line with the end of the line symbol

    return s;           // returning the pointer to the read string
}