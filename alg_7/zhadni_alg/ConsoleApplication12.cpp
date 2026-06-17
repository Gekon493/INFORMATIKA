#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007; // Модуль для ответа

int countWays(int n, int k) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;


    for (int i = 2; i <= n; i++) {

        for (int j = 1; j <= k && i - j >= 1; j++) {

            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    return dp[n];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << countWays(n, k) << endl;
    return 0;
}