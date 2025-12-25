#include <iostream>
#include <locale.h>

int findMin(const int* arr, int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

void multiplyArray(int* arr, int size, int multiplier) {
    for (int i = 0; i < size; ++i) {
        arr[i] *= multiplier;
    }
}

void printArray(const int* arr, int size, const std::string& name) {
    std::cout << name << ": ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int SIZE = 5;
    int A[SIZE], B[SIZE];
    int A_copy[SIZE], B_copy[SIZE];

    std::cout << "Введите " << SIZE << " элементов для массива A:" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cin >> A[i];
        A_copy[i] = A[i];
    }

    std::cout << "Введите " << SIZE << " элементов для массива B:" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cin >> B[i];
        B_copy[i] = B[i];
    }

    int minA = findMin(A, SIZE);
    int minB = findMin(B, SIZE);

    multiplyArray(A, SIZE, minA);
    multiplyArray(B, SIZE, minB);

    std::cout << "\nИсходные массивы:" << std::endl;
    printArray(A_copy, SIZE, "Массив A");
    printArray(B_copy, SIZE, "Массив B");

    std::cout << "\nМинимальные элементы: A=" << minA << ", B=" << minB << std::endl;

    std::cout << "\nПреобразованные массивы (каждый элемент умножен на минимум своего массива):" << std::endl;
    printArray(A, SIZE, "Массив A'");
    printArray(B, SIZE, "Массив B'");
    system("pause")
    return 0;
}
