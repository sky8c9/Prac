#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e9 + 8;

void task() {
    int n;
    cin >> n;

    vector<int> h(n);
    vector<int> dp (n + 8, MAX);
    dp[0] = 0;
    for(int&val : h) cin >> val;
    for(int i = 0; i < n; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
        dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
    }

    cout << dp[n - 1] << endl;
}

int main() {
    task();
    return 0;
}