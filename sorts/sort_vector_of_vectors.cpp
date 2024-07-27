#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<std::vector<int>> matrix = {
        {3, 5, 2},
        {1, 2, 8},
        {4, 1, 6},
    };

    // Sort by the first element of each vector
    std::sort(matrix.begin(), matrix.end(), [](const auto& a, const auto& b) {
        return a[0] < b[0];
    });

    std::cout << "Sorted by first element:\n";
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }

    // Sort by the second element of each vector
    std::sort(matrix.begin(), matrix.end(), [](const auto& a, const auto& b) {
        return a[1] < b[1];
    });

    std::cout << "Sorted by second element:\n";
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}