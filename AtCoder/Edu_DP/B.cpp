#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e9 + 8;

void task() {
    int n, k;
    cin >> n >> k; 

    vector<int> h(n);
    vector<int> dp (n + k, MAX);
    dp[0] = 0;
    for(int&val : h) cin >> val;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i + j] = min(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
        }
    }

    cout << dp[n - 1] << endl;
}

int main() {
    task();
    return 0;
}