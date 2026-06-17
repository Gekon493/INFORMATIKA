#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void parallelSort(vector<int>& data, int low, int high, int threadCount) {
    if (low >= high) return;
    if (threadCount <= 1 || (high - low) < 10000) {
        quickSort(data, low, high);
        return;
    }
    int pi = partition(data, low, high);
    int leftLen = pi - low;
    int rightLen = high - pi;
    int leftThreads = threadCount / 2;
    if (leftLen > rightLen) {
        thread tLeft(parallelSort, ref(data), low, pi - 1, leftThreads);
        parallelSort(data, pi + 1, high, threadCount - leftThreads);
        tLeft.join();
    }
    else {
        thread tRight(parallelSort, ref(data), pi + 1, high, leftThreads);
        parallelSort(data, low, pi - 1, threadCount - leftThreads);
        tRight.join();
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> testSizes = {
        100000, 200000, 300000, 400000, 500000,
        600000, 700000, 800000, 900000, 1000000
    };
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 50000);

    for (int sz : testSizes) {
        vector<int> base(sz);
        for (int& v : base) v = dist(gen);

        vector<int> a1 = base;
        auto t1 = chrono::high_resolution_clock::now();
        quickSort(a1, 0, a1.size() - 1);
        auto t2 = chrono::high_resolution_clock::now();
        double timeSeq = chrono::duration_cast<chrono::microseconds>(t2 - t1).count() / 1000000.0;

        vector<int> a2 = base;
        auto t3 = chrono::high_resolution_clock::now();
        parallelSort(a2, 0, a2.size() - 1, 2);
        auto t4 = chrono::high_resolution_clock::now();
        double time2 = chrono::duration_cast<chrono::microseconds>(t4 - t3).count() / 1000000.0;

        vector<int> a4 = base;
        auto t5 = chrono::high_resolution_clock::now();
        parallelSort(a4, 0, a4.size() - 1, 4);
        auto t6 = chrono::high_resolution_clock::now();
        double time4 = chrono::duration_cast<chrono::microseconds>(t6 - t5).count() / 1000000.0;

        vector<int> a8 = base;
        auto t7 = chrono::high_resolution_clock::now();
        parallelSort(a8, 0, a8.size() - 1, 8);
        auto t8 = chrono::high_resolution_clock::now();
        double time8 = chrono::duration_cast<chrono::microseconds>(t8 - t7).count() / 1000000.0;

        cout << "Размер: " << sz << "\n";
        cout << "Обычная: " << timeSeq << " c\n";
        cout << "2 потока: " << time2 << " c\n";
        cout << "4 потока: " << time4 << " c\n";
        cout << "8 потоков: " << time8 << " c\n\n";
    }
    cin.get();
    return 0;
}
