#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task() {
    int n, m;
    cin >> n >> m;

    vector<string> ss(n);
    for(string& s : ss) cin >> s;

    int ans = 1e9;
    for(int i = 0; i < (1 << n); i++) {
        int seen = 0;
        int cnt = 0;

        for(int j = 0; j < n; j++) {
            if (i >> j & 1) {
                ++cnt;

                for(int k = 0; k < m; k++) {
                    if (ss[j][k] == 'o') {
                        seen |= (1 << k);
                    }
                }
            }
        }

        if (seen == (1 << m) - 1) {
            ans = min(ans, cnt);
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}