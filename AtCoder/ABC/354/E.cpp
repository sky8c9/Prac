#include <iostream>
#include <vector>

using namespace std;
void task() {
    int n;
    cin >> n;

    vector<pair<int, int>> ab;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        ab.emplace_back(a, b);
    }

    vector<bool> dp(1 << n, false);
    dp[0] = false;
    for(int s = 0; s < (1 << n); s++) {
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if (s >> i & 1 || s >> j & 1) continue;
                if (ab[i].first == ab[j].first || ab[i].second == ab[j].second) {
                    int nxt = s | (1 << i) | (1 << j);
                    dp[nxt] = dp[nxt] | !dp[s];
                }
            }
        }
    }
   
    if (dp[(1 << n) - 1]) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
}

int main() {
    task();
    return 0;
}