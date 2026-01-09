#ifndef PRINT_H
#define PRINT_H


#include <vector>

class Print {
public:
    void PrintMatrix(const std::vector<std::vector<float>>& matrix);
    void Test(double);
    void PrintMatrixInt(const std::vector<std::vector<int>>& matrix);
};

#endif