#include <algorithm>
#include <vector>
#include <iostream>

struct Person {
    std::string name;
    int age;
    double height;

    Person(std::string n, int a, double h) : name(n), age(a), height(h) {}
};

int main() {
    std::vector<Person> people = {
        {"Alice", 30, 5.5},
        {"Bob", 25, 5.8},
        {"Charlie", 35, 5.7},
    };

    // Sort by age
    std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.age < b.age;
    });

    std::cout << "Sorted by age:\n";
    for (const auto& person : people) {
        std::cout << person.name << ", " << person.age << ", " << person.height << '\n';
    }

    // Sort by height
    std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.height < b.height;
    });

    std::cout << "Sorted by height:\n";
    for (const auto& person : people) {
        std::cout << person.name << ", " << person.age << ", " << person.height << '\n';
    }

    return 0;
}
