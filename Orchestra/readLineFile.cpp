#include "readLineFile.h"

char* readLineFile(std::ifstream& file) {
    char c;
    int size = 0;

    // начальное предположение о размере строки.
    int bufferSize = 1;
    char* buffer = new char[bufferSize];

    // Пока есть символы и они не символ перевода строки
    while (file.get(c) && c != '\n') {
        // Проверяем, полон ли буфер
        if (size == bufferSize - 1) {
            // Если буфер полон, увеличиваем его размер
            bufferSize *= 2;
            char* newBuffer = new char[bufferSize];
            // Копируем данные из старого буфера в новый
            for (int i = 0; i < size; ++i) {
                newBuffer[i] = buffer[i];
            }
            // Удаляем старый буфер
            delete[] buffer;
            buffer = newBuffer;
        }

        // Сохраняем символ в буфер
        buffer[size] = c;
        ++size;
    }

    // Уменьшаем буфер до нужного размера
    char* trimmedBuffer = new char[size + 1];
    for (int i = 0; i < size; ++i) {
        trimmedBuffer[i] = buffer[i];
    }
    trimmedBuffer[size] = '\0';

    // Удаляем оригинальный буфер
    delete[] buffer;

    return trimmedBuffer;
}