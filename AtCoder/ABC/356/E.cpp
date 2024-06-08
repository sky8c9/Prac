#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

const int MAX = 1e6;

void task() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<ll> freq(MAX + 1, 0);
    set<int> vals;
    for(int&val : a) {
        cin >> val;
        ++freq[val];
        vals.insert(val);
    }

    vector<ll> prefS(MAX + 2, 0);
    for(int i = 0; i <= MAX; i++) prefS[i + 1] = prefS[i] + freq[i];
    
    vector<ll> cnt(MAX + 1);
    for(int val : vals) {
        ll cnt1 = prefS[min(2*val, MAX + 1)] - prefS[val];
        cnt1 -= freq[val];
        cnt1 *= freq[val];
        cnt1 += freq[val] * (freq[val] - 1) / 2;
        cnt[1] += cnt1;

        for(int j = 2; j * val <= MAX; j++) {
            int l = j * val;
            int r = min(MAX + 1, (j + 1) * val);
            cnt[j] += (prefS[r] - prefS[l]) * freq[val];
        }
    }

    ll ans = 0;
    for(int i = 1; i <= MAX; i++) {
        ans += cnt[i] * i;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}
