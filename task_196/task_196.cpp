#include <iostream>
#include <fstream>
#include "Random.h"

int main()
{
	int size;
	
	RandomValue();

	std::ifstream Value("input.txt");

	Value >> size;

	int** Matrix = new int* [size];
	for (int i = 0; i < size; ++i) {
		Matrix[i] = new int[size] {};
	}
	
	int numbers = 1;
	int temp = size;
	for (int i = 0; i < (size+1)/2; ++i) {
		for (int j = i; j < size - i; ++j) {
			Matrix[i][j] = numbers++;
		}
		for (int q = i+1; q < size - i; ++q) {
			Matrix[q][size-1-i] = numbers++;
		}
		for (int p = size-2; p >= i; --p) {
			Matrix[size-1-i][p] = numbers++;
		}
		for (int j = size-2-i; j > i; --j) {
			Matrix[j][i] = numbers++;
		}
		
	}
	
	printArray1(Matrix, size);
	printArray(Matrix, size);

	for (int i = 0; i < size; ++i) {
		delete[] Matrix[i];
	}
	delete[] Matrix;
}
