#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
const ll MAX = 1e18;

void task() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> pos;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            pos.push_back(i);
        }
    }

    int m = pos.size();
    vector<ll> lr(m, 0);
    vector<ll> rl(m, 0);
    lr[0] = rl[m - 1] = 0;
    for(int i = 1; i < m; i++) {
        int d1 = pos[i] - pos[i - 1] - 1;
        int d2 = pos[m - i] - pos[m - i - 1] - 1;

        lr[i] = lr[i - 1] + (ll) d1 * i;
        rl[m - i - 1] = rl[m - i] + (ll) d2 * i;
    }

    ll ans = MAX;
    for(int i = 0; i < m; i++) {
        ans = min(ans, lr[i] + rl[i]);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}