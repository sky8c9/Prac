#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<pair<ll, ll>> ans;

void findI(ll l, ll r, ll ql, ll qr) {
    if (r <= ql || l >= qr) return;
    if (l >= ql && r <= qr) {
        ans.push_back({l, r});
        return;
    }
    
    ll mid = l + (r - l) / 2;
    findI(l, mid, ql, qr);
    findI(mid, r, ql, qr);
}

void task() {
    ll l, r;
    cin >> l >> r;

    ll sz = 1;
    while(sz < r) sz <<= 1;

    findI(0, sz, l, r);
    cout << ans.size() << endl;
    for(auto[ll, rr] : ans) {
        cout << ll << " " << rr << endl;
    }
}

int main() {
    task();
    return 0;
}