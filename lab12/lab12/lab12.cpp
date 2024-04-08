#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, int> findMinPosition(const std::vector<std::vector<int>>& matrix) {
    int min = matrix[0][0];
    std::pair<int, int> minPos = { 0, 0 };

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                minPos = { i, j };
            }
        }
    }

    return minPos;
}

void swapRowAndColumn(std::vector<std::vector<int>>& matrix, int row, int col) {
    std::swap(matrix[row], matrix[col]);
    for (size_t i = 0; i < matrix.size(); ++i) {
        std::swap(matrix[i][row], matrix[i][col]);
    }
}

void sortRowsDescendingBySecondRow(std::vector<std::vector<int>>& matrix) {
    std::sort(matrix.begin(), matrix.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] > b[1];
        });
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    std::vector<std::vector<int>> matrix = {
        {9, 8, 7},
        {4, 5, 6},
        {1, 2, 3}
    };

    std::pair<int, int> minPos = findMinPosition(matrix);
    int minRow = minPos.first;
    int minCol = minPos.second;

    swapRowAndColumn(matrix, minRow, minCol);

    std::cout << "ћатриц€ пiсл€ обмiну р€дка i стовпц€ з мiнiмальним елементом:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    sortRowsDescendingBySecondRow(matrix);

    std::cout << "\nћатриц€ пiсл€ сортуванн€ р€дкiв за другим р€дком у спадаючому пор€дку:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}