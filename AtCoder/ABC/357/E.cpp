#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    vector<int> nxt(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        nxt[i] = val;
    }

    ll ans = 0;
    vector<bool> seen(n + 1, false);
    vector<int> cSz(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if (seen[i]) continue;
        
        int cur = i;
        int len = 0;
        bool cycled = false;
        map<int, int> m;
        while(1) {
            if (m[cur]) {
                cycled = true;
                break;
            }

            if (cur == 0 || seen[cur]) break;
            m[cur] = ++len;
            seen[cur] = true;
            cur = nxt[cur];
        }

        if (cycled) {
            int clen = len - m[cur] + 1;
            ans += (ll) clen * clen;
            for(auto [v, idx] : m) {
                if (idx >= m[cur]) cSz[v] = clen;
            }
        }
    }
    
    vector<ll> dp(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if (dp[i] || cSz[i]) continue;

        auto compute = [&](auto compute, int u) -> ll {
            if (cSz[u]) return cSz[u];
            if (dp[u]) return dp[u];

            dp[u] = 1 + compute(compute, nxt[u]);
            ans += dp[u];

            return dp[u];
        };

        compute(compute, i);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}

