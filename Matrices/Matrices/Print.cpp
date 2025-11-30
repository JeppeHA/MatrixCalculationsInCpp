#include <iostream>
#include<vector>
#include "Print.h"

using namespace std;

void Print::PrintMatrix(const std::vector<std::vector<float>>& matrix) {

	cout << "-----------" << endl;
	for (int i = 0; i < matrix.size(); i++) {
		cout << "| ";
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " | ";
		}
		cout << endl;
		cout << "-----------" << endl;

	}
}

