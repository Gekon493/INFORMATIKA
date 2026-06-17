#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxCrossingSum(vector<int>& arr, int left, int mid, int right) {
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }
    return leftSum + rightSum;
}

int maxSubarraySum(vector<int>& arr, int left, int right) {

    if (left == right) {
        return arr[left];
    }
    int mid = left + (right - left) / 2;
    int leftMax = maxSubarraySum(arr, left, mid);
    int rightMax = maxSubarraySum(arr, mid + 1, right);
    int crossMax = maxCrossingSum(arr, left, mid, right);

    return max({ leftMax, rightMax, crossMax });
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = maxSubarraySum(arr, 0, n - 1);
    cout << result << endl;

    return 0;
}