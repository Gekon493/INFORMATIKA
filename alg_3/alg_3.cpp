#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void combSort(vector<int>& arr) {
    int n = arr.size();
    int step = n;
    bool swapped = true;
    while (step > 1 || swapped) {
        step = (int)(step / 1.3);
        if (step < 1) step = 1;
        swapped = false;
        for (int i = 0; i + step < n; i++) {
            if (arr[i] > arr[i + step]) {
                swap(arr[i], arr[i + step]);
                swapped = true;
            }
        }
    }
}

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

int main() {
    vector<int> sizes = { 100000, 200000, 300000, 400000, 500000,
                          600000, 700000, 800000, 900000, 1000000 };

    for (int size : sizes) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 100000;
        }

        vector<int> arr1 = arr; 
        vector<int> arr2 = arr; 
        vector<int> arr3 = arr; 

        auto start = chrono::high_resolution_clock::now();
        combSort(arr1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration1 = end - start;

        start = chrono::high_resolution_clock::now();
        mergeSort(arr2, 0, size - 1);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration2 = end - start;

        start = chrono::high_resolution_clock::now();
        quickSort(arr3, 0, size - 1);
        end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration3 = end - start;

        cout << "Size: " << size << endl;
        cout << "Comb Sort: " << duration1.count() << " sec" << endl;
        cout << "Merge Sort: " << duration2.count() << " sec" << endl;
        cout << "Quick Sort: " << duration3.count() << " sec" << endl;
        cout << endl;
    }
    return 0;
}
