#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>
#include <time.h>
//
#include "str_me.h" // подключаем заголовочный файл

/**
 * @brief The main function
 *
 * This function is the program's entry point and is called when the program starts.
 * It's responsible for initializing the program and starting the main loop.
 *
 * @return 0 on success
 */
int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    char* str = (char*)malloc(100*sizeof(char));
    if (str == NULL) {
        printf("Memory not allocated. \n");
        return -1;
    }
    // заполнение строки
    strCopy(str, "No Fate but what we make");
    int pos = 0;
    
    // вывод посимвольно строки в цикле
    while (1){
        if (*(str+pos) == '\0') {
            printf("\n");
            break; // прерывание цикла если строка закончилась
        }
        printf("%c", *(str+pos));
        pos++;
    }

    // вычисление длины строки
    int len = 0;
    while (*(str+len) != '\0') len++;
    printf("Длина строки: %d\n", len);

    // перевод строки в верхний регистр
    for (int i = 0; *(str+i) != '\0'; i++) {
        *(str+i) = toUpper(*(str+i));
    }
    printf("Строка в верхнем регистре: %s\n", str);

    // перевод строки в нижний регистр
    for (int i = 0; *(str+i) != '\0'; i++) {
        *(str+i) = toLower(*(str+i));   
    }
    printf("Строка в нижнем регистре: %s\n", str);
    //CaMeL StYlE
    for (int i = 0; *(str+i) != '\0'; i++) {
        *(str+i) = (i%2) ? toUpper(*(str+i)) : toLower(*(str+i));
    }
    printf("Строка в Camel Style: %s\n", str);
    // освобождаем память, выделенную под строку
    free(str);
    
    // Check for null pointer reference
    return 0; 
}
/**
 * @brief Convert a character to upper case
 *
 * If the character is a lowercase letter, converts it to the
 * corresponding uppercase letter. Otherwise, leaves the character
 * unchanged.
 *
 * @param character character to convert
 * @return character converted to uppercase
 */
char toUpper(char character) {
    if (character >= 'a' && character <= 'z') {
        character -= OFFSET_CHAR;
    }
    return character;
}
/**
 * @brief Convert a character to lower case
 *
 * If the character is an uppercase letter, converts it to the
 * corresponding lowercase letter. Otherwise, leaves the character
 * unchanged.
 *
 * @param character character to convert
 * @return character converted to lowercase
 */
char toLower(char character) {
    if (character >= 'A' && character <= 'Z') {
        return character + OFFSET_CHAR;
    }
    return character;
}
/**
 * @brief Copies a string from src to dest
 *
 * Copies a string from src to dest, up to the null character.
 *
 * @param dest destination string
 * @param src source string
 */
void strCopy(char* dest, char* src) {
    for (; *src != '\0';) {
        *dest++ = *src++;
    }
}