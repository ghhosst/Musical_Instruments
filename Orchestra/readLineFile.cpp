#include "readLineFile.h"

char* readLineFile(std::ifstream& file) {
    char c;
    int size = 0;

    int bufferSize = 1;
    char* buffer = new char[bufferSize];

    // As long as there are characters and they are not a newline character
    while (file.get(c) && c != '\n') {
        // Check if the buffer is full
        if (size == bufferSize - 1) {
            // If the buffer is full, increase its size
            bufferSize *= 2;
            char* newBuffer = new char[bufferSize];
            // Copying data from the old buffer to the new one
            for (int i = 0; i < size; ++i) {
                newBuffer[i] = buffer[i];
            }
            // Deleting the old buffer
            delete[] buffer;
            buffer = newBuffer;
        }

        // Saving the character to the buffer
        buffer[size] = c;
        ++size;
    }

    // Reducing the buffer to the desired size
    char* trimmedBuffer = new char[size + 1];
    for (int i = 0; i < size; ++i) {
        trimmedBuffer[i] = buffer[i];
    }
    trimmedBuffer[size] = '\0';

    // Deleting the original buffer
    delete[] buffer;

    return trimmedBuffer;
}