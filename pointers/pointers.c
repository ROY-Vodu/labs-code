#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "pointers.h"


int main(){
    int size_n, size_m = 0;
    // Массив NxM
    printf("Введите размер массива (Не больше %dx%d) в формате NxM: ", ARR_MAX_SIZE, ARR_MAX_SIZE); 
    // ввод с консоли размера массива
    scanf("%dx%d*[^\n]", &size_n, &size_m);
    if (size_n > ARR_MAX_SIZE || size_m > ARR_MAX_SIZE){
        printf("Массив не может быть больше %dx%d\n", ARR_MAX_SIZE, ARR_MAX_SIZE);
        return -1;
    }
    // выделение памяти под массив
    signed int* current_arr = (int*)malloc(size_n*size_m*sizeof(int));
    if (current_arr == NULL) {
        printf("Что то с памятью моей стало... \n");
        return -1;
    }
    fillMass(current_arr, &size_n, &size_m);
    printMass(current_arr, &size_n, &size_m);

    //копирование массива
    signed int* copy_arr = (int*)malloc(size_n*size_m*sizeof(int));
    if (copy_arr == NULL) {
        printf("Что то с памятью моей стало... \n");
        return -1;
    }
    printf("\n\n--------------Транспонированная матрица--------------\n\n");
    memcpy(copy_arr, current_arr, size_n*size_m*sizeof(int));
    //транспонирование матрицы copy_arr  NxM в MxN
    for (int i=0; i<size_n; i++){
        for (int j=0; j<size_m; j++){
            *(copy_arr+j*size_n+i) = *(current_arr+i*size_m+j);
        }
    }
    printMass(copy_arr, &size_m, &size_n);
    // освобождение памяти
    free(current_arr);
    free(copy_arr);
    return 0;
}


void fillMass(signed int* arr, int* n, int* m){
    srand(time(0));
    for (int i=0; i<*n; i++){
        for (int j=0; j<*m; j++){
            *(arr+i*(*m)+j) = rand() % 100 - 50;
        }
    }
}

void printMass(signed int* arr, int* n, int* m){
    for (int i=0; i<*n; i++){
        for (int j=0; j<*m; j++){
            printf("%3d ", *(arr+i*(*m)+j));
        }
        printf("\n");
    }
}