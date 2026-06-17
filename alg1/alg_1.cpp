#include <iostream>
#include <chrono>
#include <unordered_set>
#include <clocale>
#include <cmath>

void measureErasePerformance(std::size_t size) {
    std::unordered_set<int> numbers;
    for (std::size_t i = 0; i < size; ++i) {
        numbers.insert(static_cast<int>(i));
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (std::size_t i = 0; i < size; ++i) {
        auto it = numbers.find(static_cast<int>(i));
        if (it != numbers.end()) {
            numbers.erase(it);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    double ms = duration.count() * 1000.0;
    int roundedMs = static_cast<int>(std::round(ms));

    std::cout << size << " " << roundedMs << "\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Размер\n";
    std::cout << "Время(мс)\n";
    for (std::size_t size = 1000; size <= 1000000; size *= 2) {
        measureErasePerformance(size);
    }

    std::cout << "\nНажмите Enter для выхода...";
    std::cin.get();
    return 0;
}
