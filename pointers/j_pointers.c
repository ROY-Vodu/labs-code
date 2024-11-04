
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
Ссылки и указатели "для маленьких"
*/

int main(){

    // объявление переменных
    int a = 10; // обычная переменная
    int* ptr_a = &a; // указатель на переменную a (ссылка, адрес в памяти)
    printf("a = %d\n", a); // выведет значение переменной a = 10
    printf("&a = %p\n", &a); // выведет адрес переменной a (что то вроде 0x7fffffffdd84)
    printf("ptr_a = %p\n", ptr_a); // выведет адрес переменной ptr_a (что то вроде 0x7fffffffdd84)
    printf("*ptr_a = %d\n", *ptr_a); // выведет значение переменной a = 10
    //
    /*
    &a = ptr_a Адрес одинаковый 
    */
    // массив.
    int size_arr1 = 10;
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int buffer[2048]; // просто буфер, для теста
    // переменная arr указывают на первый элемент массива
    // и содержимое этой переменной - адрес (!!!)
    //
    // перемещение по массиву
    // адрес + размер элемента массива (типа)
    // к примеру: arr1[3] эквивалентно *(arr1+3) <----  внутри 3 - это 3*sizeof(int) байт
    // смещение в памяти по указателю

    int* ptr_arr1_1 = &arr1[1]; // указатель на первый (!не нулевой) элемент массива

    printf("arr1[0] = %i\n", arr1[0]); // выведет значение нулевого элемента массива
    printf("arr1[1] = %i\n", arr1[1]); // выведет значение первого элемента массива
    printf("ptr = %p\n", ptr_arr1_1); // выведет адрес первого элемента массива
    printf("&ptr = %p\n", &ptr_arr1_1); // выведет адрес переменной ptr_arr1_1
    printf("arr1[1] = %d\n", *ptr_arr1_1); // выведет значение первого элемента массива

    // делаем новый массив на основании массива arr
    // но не присваиваем значения, а работаем с ним через указатели
    short int size_arr2 = 5; // размер нового массива
    int* arr2 = &arr1[4]; // указатель на начало нового массива (c 4-го элемента массива arr)
    //
    // вывод массива arr
    for (int i=0; i<size_arr1; i++){
        printf("%2d ", *(arr1+i));
    }
    printf("\n");

    //вывод массива arr2

    // для выравнивания вывода и наглядности
    for(int i=0; i<size_arr2-1; i++)printf("   ");
    
    for (int i=0; i<size_arr2; i++){
        printf("%2d ", *(arr2+i));
    }
    printf("\n");
    // а теперь меняем значения элементов массива arr2 и выводим arr1 (!!!!)
    for (int i=0; i<size_arr2; i++){
        *(arr2+i) *= 2;
    }
    // вывод
    for (int i=0; i<size_arr1; i++){
        printf("%2d ", *(arr1+i));
    }
    printf("\n");
    printf("как то так работают указатели... =)\n");
    return 0;
}
