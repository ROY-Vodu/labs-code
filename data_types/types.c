
#include <stdio.h>

int main(){
    /*
    Всего 4 типа данных в C:
    char - 1 байт
    int - 4 байта
    float - 4 байта
    double - 8 байт
    void - 0 байт

    Типы могут быть модифицированы:
    signed - знаковые
    unsigned - беззнаковые
    short - 2 байта
    long - 8 байт

    */

    // основные типы
    printf("Pазмер char %d\n", sizeof(char)); // целочисленные
    printf("Pазмер int %d\n", sizeof(int));   // целочисленные
    printf("Pазмер float %d\n", sizeof(float)); // вещественные
    printf("Pазмер double %d\n", sizeof(double)); // вещественные
    // типы с модификаторами
    // целочисленные
    printf("Pазмер short int %d\n", sizeof(short int));
    printf("Pазмер long int %d\n", sizeof(long int));
    printf("Pазмер long long int %d\n", sizeof(long long int));
    // вещественные
    printf("Pазмер double %d\n", sizeof(double));
    printf("Pазмер long double %d\n", sizeof(long double));

    // Присваивание и работа с типами данных
    char a = 'a';
    unsigned char aa = 'a';
    signed char aaa = 'a';
    //
    int b = 10;
    unsigned int bb = 10;
    signed int bbb = 10;
    
    short int c = 10;
    unsigned short int cc = 10;
    signed short int ccc = 10;
    // для обозначения целых чисел и их величин могут
    // приметяться суффиксы:
    // u (U) - беззнаковые
    // l (L) - 8 байт
    // ul (UL) - беззнаковые 8 байт
    // ll (LL) - 8 байт
    // ull (ULL) - беззнаковые 8 байт
    // f - вещественные
    long int d = 10L;
    unsigned long int dd = 10UL;
    signed long int ddd = 10l;
    
    long long int e = 10ll;
    unsigned long long int ee = 10ULL;
    signed long long int eee = 10ll;

    double f = 10.0f;
    long double ff = 10.0F;

    float g = 10.0f;


    
    
    

    return 0;
}