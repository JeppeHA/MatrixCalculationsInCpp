#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "Print.h"

using namespace std;

int rows = 1000;
int cols = 1000;

vector<vector<int>> matrixA = {
	{1, 2},
	{3, 4}
};

vector<vector<int>> matrixB = {
	{5, 6},
	{7, 8}
};


void PopulateMatrix(vector<vector<int>>& matrix, int rows, int cols) {
	matrix.resize(rows);
	for (int i = 0; i < rows; i++) {
		matrix[i].resize(cols);
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = rand() % 10; 
		}
	}
}

vector<vector<int>> MultiplyMatrices(vector<vector<int>> matrixA, vector<vector<int>> matrixB) {
	vector<vector<int>> resultMatrix(rows, vector<int>(cols, 0));

	for (int i = 0; i < resultMatrix.size(); i++) {
		for (int j = 0; j < resultMatrix[i].size(); j++) {
			for (int k = 0; k < 1000; k++) {
				resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
	return resultMatrix;
}

vector<vector<float>> InverseMatrix(vector<vector<float>> matrix) {

	vector<vector<float>> inverseMatrix(matrix.size(), vector<float>(matrix[0].size(), 0));

	inverseMatrix[0][0] = matrix[1][1];
	inverseMatrix[0][1] = -matrix[0][1];
	inverseMatrix[1][0] = -matrix[1][0];
	inverseMatrix[1][1] = matrix[0][0];

	float determianant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

	for (int row = 0; row < inverseMatrix.size(); row++) {
		for (int col = 0; col < inverseMatrix[row].size(); col++) {
			inverseMatrix[row][col] *= (1 / determianant);
		}

	}

	return inverseMatrix;

}

vector<float> CalculateVariabels(vector<vector<float>> matrix, float c1, float c2) {
	vector<float> variables;
	vector<vector<float>> inverseMatrix = InverseMatrix(matrix);
	variables.push_back(inverseMatrix[0][0] * c1 + inverseMatrix[0][1] * c2);
	variables.push_back(inverseMatrix[1][0] * c1 + inverseMatrix[1][1] * c2);
	return variables;
}


int main() {

	Print printer;
	// Columns in the first matrix must be equal to rows in the second matrix 
	// Else you cannot multiply them

	// The resulting matrix will have the number of rows of the first matrix and the number of columns of the second matrix

	printf("Hello, Matrices!\n");


	//cout << "Calculating A x B..." << endl;

	//cout << "Populating large matrices..." << endl;

	//PopulateMatrix(matrixA, rows, cols);

	//PopulateMatrix(matrixB, rows, cols);
	//cout << "Resulting Matrix (A x B):" << endl;
	//cout << MultiplyMatrices(matrixA, matrixB).size() * MultiplyMatrices(matrixA, matrixB)[0].size() << " values" << endl;
	vector<vector<float>> smallMatrix = {
		{4,-2},
		{5,3}
	};

	cout << "We have to equations:" << endl;
	cout << "4x - 2y = 0" << endl;
	cout << "5x + 3y = -11" << endl;

	cout << "Which we want to solve for x and y using matrices" << endl;

	cout << "First we need to express them as a matrix:" << endl;

	printer.PrintMatrix(smallMatrix);

	cout << "Now we need to find the inverse of the matrix:" << endl;

	printer.PrintMatrix(InverseMatrix(smallMatrix));

	cout << "Now we can calculate the variables x and y by multiplying thourgh the inverse" << endl;

	vector<float> results = CalculateVariabels(smallMatrix, 0, -11);

	cout << "X: " << results[0];
	cout << "Y: " << results[1];

	return 0;
}






