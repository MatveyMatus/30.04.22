#include "Random.h"

void RandomValue(){
	srand(time(NULL));
	std::ofstream RandomValue("input.txt");

	int size = rand() % 10 + 2;

	RandomValue << size << std::endl;
	RandomValue.close();
}

void printArray(int** arr,int size) {
	std::ofstream result("output.txt");

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			result << arr[i][j] << " ";
		}
		result << std::endl;
	}

	result.close();
}
void printArray1(int** arr, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}