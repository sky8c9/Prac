#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

struct Dsu {
    vector<int> parents;
    vector<int> ranks;

    Dsu(int n) {
        parents.resize(n);
        ranks.resize(n);
        
        for(int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 1;
        }
    }

    int find(int cur) {
        if (cur != parents[cur]) parents[cur] = find(parents[cur]);
        return parents[cur];
    }

    bool join(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return false;
        if (ranks[pa] > pb) parents[pb] = pa;
        else {
            if (ranks[pa] == ranks[pb]) ranks[pb]++;
            parents[pa] = pb;
        }

        return true;
    }
};

ll pow_mod(ll x, ll y, ll mod) {
    ll ans = 1;
    x %= mod;

    while(y) {
        if (y & 1) {
            ans *= x;
            ans %= mod;
        }

        x *= x;
        x %= mod;
        y >>= 1;
    }

    return ans;
}

void task() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    multimap<ll, pair<int, int>> mm;
    for(ll& val : a) cin >> val;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ll v1 = pow_mod(a[i], a[j], m);
            ll v2 = pow_mod(a[j], a[i], m);
            ll sum = (v1 + v2) % m;
            mm.insert({-sum, make_pair(i, j)});
        }
    }

    int cnt = 0;
    ll ans = 0;
    Dsu uf(n);
    for(auto[score, uv] : mm) {
        if (cnt == n) break;

        bool flag = uf.join(uv.first, uv.second);
        if (flag) {
            ans -= score;
            ++cnt;
        }
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}