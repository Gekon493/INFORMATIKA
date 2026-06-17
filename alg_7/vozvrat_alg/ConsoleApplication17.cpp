#include <iostream>
#include <vector>
using namespace std;

bool findSubsetSum(vector<int>& arr, int index, int target, vector<int>& subset) {
    if (target == 0) {
        return true;
    }

    if (index >= arr.size() || target < 0) {
        return false;
    }

    subset.push_back(arr[index]);
    if (findSubsetSum(arr, index + 1, target - arr[index], subset)) {
        return true;
    }
    subset.pop_back();

    if (findSubsetSum(arr, index + 1, target, subset)) {
        return true;
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> subset;
    if (findSubsetSum(arr, 0, k, subset)) {
        cout << "YES" << endl;
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}