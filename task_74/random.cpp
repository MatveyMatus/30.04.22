#include "random.h"

void RandomValue(){
	srand(time(NULL));
	std::ofstream Values("input.txt");
	Values << rand() % 9 + 1 << " " << rand() % 9 + 1;
	Values.close();
}


int* winPlayer(int* arr, int size) {
	int temp = 0;
	for (int i = 0; i < size+1; ++i) {
		if (i % 2 != 0) {
			arr[i] = -1;
			temp++;
		}
	}
	int* arr2 = new int[temp];
	int k = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] != -1) {
			arr2[k++] = arr[i];
		}
	}
	return arr2;
}
