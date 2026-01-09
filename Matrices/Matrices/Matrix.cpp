#include <iostream>
#include<vector>
#include "Matrix.h"


using namespace std;

void Matrix::PopulateMatrix(std::vector<std::vector<int>>& matrix, int rows, int cols) {
	matrix.resize(rows);
	for (int i = 0; i < rows; i++) {
		matrix[i].resize(cols);
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
}