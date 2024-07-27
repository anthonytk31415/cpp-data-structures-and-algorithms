// Sorting a Vector of Tuples
// Similarly, you can sort a vector of tuples based on specific elements.

#include <algorithm>
#include <vector>
#include <tuple>
#include <iostream>

int main() {
    std::vector<std::tuple<std::string, int, double>> data = {
        {"Alice", 30, 5.5},
        {"Bob", 25, 5.8},
        {"Charlie", 35, 5.7},
    };

    // Sort by second element (age)
    std::sort(data.begin(), data.end(), [](const auto& a, const auto& b) {
        return std::get<1>(a) < std::get<1>(b);
    });

    std::cout << "Sorted by age:\n";
    for (const auto& entry : data) {
        std::cout << std::get<0>(entry) << ", " << std::get<1>(entry) << ", " << std::get<2>(entry) << '\n';
    }

    // Sort by third element (height)
    std::sort(data.begin(), data.end(), [](const auto& a, const auto& b) {
        return std::get<2>(a) < std::get<2>(b);
    });

    std::cout << "Sorted by height:\n";
    for (const auto& entry : data) {
        std::cout << std::get<0>(entry) << ", " << std::get<1>(entry) << ", " << std::get<2>(entry) << '\n';
    }

    return 0;
}