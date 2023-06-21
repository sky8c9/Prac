#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct Bit {
    int size;
    vector<ll> bit;

    Bit(int n) {
        size = n + 1;
        bit.resize(size, 0);
    }

    void update(int i, int val) {
        ++i;
        while(i <= size) {
            bit[i] += val;
            i += i & -i;
        }
    }

    ll total(int i) {
        ++i;
        ll sum = 0;

        while(i > 0) {
            sum += bit[i];
            i -= i & -i;
        }

        return sum;
    }
};

void task() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int val;
            cin >> val;
            a.emplace_back(val, i);
        }
    }
    sort(a.begin(), a.end());

    ll ans = (ll) n * (n - 1) / 2 * m * (m + 1) / 2;
    Bit fenw(n);
    for(auto [val, idx] : a) {
        ans += fenw.total(n - 1) - fenw.total(idx);
        fenw.update(idx, 1);
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}