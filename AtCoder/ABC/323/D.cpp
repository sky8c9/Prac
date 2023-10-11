#include <iostream>
#include <map>

using namespace std;
using ll = long long;

void task() {
    int n;
    cin >> n;

    map<ll, ll> m;
    for(int i = 0; i < n; i++) {
        ll s, c;
        cin >> s >> c;
        m[s] = c;
    }

    auto itr = m.begin();
    int ans = 0;
    while(itr != m.end()) {
        auto[s, c] = *itr;
        if (c > 1) m[2 * s] += c / 2;
        if (c & 1) ++ans;
        ++itr;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}