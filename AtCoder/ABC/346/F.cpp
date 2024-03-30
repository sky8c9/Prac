#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const ll MAX = 1e18;

bool doable(ll n, ll k, vector<vector<ll>>& indices, string s, string t) {
    ll cur = 0;

    for(char c : t) {
        auto& locs = indices[c - 'a'];

        ll m = locs.size();
        if (m == 0) return false;

        ll i = lower_bound(locs.begin(), locs.end(), cur % s.size()) - locs.begin();
        ll ni = i + k - 1;

        ll curBlock = cur / s.size();
        ll added = ni / m ;
        cur = (curBlock + added) * s.size() + locs[ni % m] + 1;

        if (curBlock + added >= n) return false;
    }

    return true;
}

void task() {
    ll n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    vector<vector<ll>> indices(26);
    for(int i = 0; i < s.size(); i++) {
        indices[s[i] - 'a'].push_back(i);
    }

    ll lo = 0;
    ll hi = MAX;
    while(lo < hi) {
        ll mid = lo + (hi - lo) / 2 + 1;
        if (doable(n, mid, indices, s, t)) lo = mid;
        else hi = mid - 1;
    }

    cout << lo << endl;
}

int main() {
    task();
    return 0;
}