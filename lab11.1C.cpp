#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>

// Функція для підрахунку входжень заданих символів у рядку
void countCharacters(const char* line, int* plusCount, int* minusCount, int* equalCount) {
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '+') {
            (*plusCount)++;
        }
        else if (line[i] == '-') {
            (*minusCount)++;
        }
        else if (line[i] == '=') {
            (*equalCount)++;
        }
    }
}

// Функція для зчитування вмісту файлу і підрахунку символів
void countSymbolsInFile(const char* filename, int* plusCount, int* minusCount, int* equalCount) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Не вдалося відкрити файл: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        countCharacters(line, plusCount, minusCount, equalCount);
    }

    fclose(file);
}

// Основна функція
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char* filename = "t.txt";
    int plusCount = 0, minusCount = 0, equalCount = 0;

    countSymbolsInFile(filename, &plusCount, &minusCount, &equalCount);

    printf("Кількість входжень символів:\n");
    printf("'+': %d\n", plusCount);
    printf("'-': %d\n", minusCount);
    printf("'=': %d\n", equalCount);

    return 0;
}
