#include <iostream>

void sortMatrixBySecondRow(int matrix[][3]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2 - i; ++j) {
            if (matrix[1][j] < matrix[1][j + 1]) {
                for (int k = 0; k < 3; ++k) {
                    int temp = matrix[j][k];
                    matrix[j][k] = matrix[j + 1][k];
                    matrix[j + 1][k] = temp;
                }
            }
        }
    }
}

int main() {
    int matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    int minElement = matrix[0][0];
    int minRowIndex = 0, minColIndex = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minRowIndex = i;
                minColIndex = j;
            }
        }
    }

    for (int k = 0; k < 3; ++k) {
        int temp = matrix[minRowIndex][k];
        matrix[minRowIndex][k] = matrix[minColIndex][k];
        matrix[minColIndex][k] = temp;
    }

    sortMatrixBySecondRow(matrix);

    std::cout << "Matrix after sorting by second row in descending order:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}