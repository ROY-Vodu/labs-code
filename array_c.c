#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>
#include <time.h>

/**
 * @brief Fill array with random numbers
 *
 * Fill array of size sArr with random numbers between 0 and 99.
 *
 * @param arr array to fill
 * @param sArr size of array
 */
void fillMass(int* arr, int sArr){ 
	srand(time(0)); // initialize random
	for(int i=0; i<sArr; i++){ // fill array with random numbers
		*(arr+i) =  rand() % 100; // random 0 - 99
	}
}

/**
 * @brief Main function
 *
 * Allocate memory for 25 integers and call fillMass to fill this array.
 * Then print out the array.
 *
 * @return 0 on success
 */
int main() {

	const int SIZE_ARRAY = 25;
	int* ptr_arr = (int*)malloc(SIZE_ARRAY*sizeof(int));
	int ss = sizeof(ptr_arr);
	fillMass(ptr_arr,25);

	// find min, max
	int min,max = 0;
	//
	for (int i=1;i<SIZE_ARRAY;i++){
		if (*(ptr_arr+min)>*(ptr_arr+i)){
			min = i;
		}
		if (*(ptr_arr+max)<*(ptr_arr+i)){
			max = i;
		}
	}
	// print min max
	printf("MIN = %d, MAX = %d\n",*(ptr_arr+min),*(ptr_arr+max));
	// перестановка мин и макс
	{
		int temp = *(ptr_arr+min);
		*(ptr_arr+min) = *(ptr_arr+max);
		*(ptr_arr+max) = temp;
	}
	// print result
	for (int i = 1; i<=25; i++){
		printf("%3d ",*(ptr_arr+i-1));
		if (i % 5 == 0) printf("\n");
	}
	//

	free(ptr_arr);
	return 0;
}
