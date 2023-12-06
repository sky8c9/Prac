#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int n, q;
vector<string> grid;
vector<vector<ll>> sum;

ll compute(ll c, ll d) {
    ll w = d / n;
    ll rw = d % n;

    ll h = c  / n;
    ll rh = c  % n;

    ll ans = h * w * sum[n][n];
    ans += sum[n][rw] * h;
    ans += sum[rh][n] * w;
    ans += sum[rh][rw];
    return ans;
}

ll get(ll a, ll b, ll c, ll d) {
    return compute(c + 1, d + 1) - compute(a, d + 1) - compute(c + 1, b) + compute(a, b);
}

void task() {
    cin >> n >> q;
    grid = vector<string>(n);
    sum = vector<vector<ll>> (n + 1, vector<ll>(n + 1, 0));
    for(string& s : grid) cin >> s;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
            sum[i + 1][j + 1] += grid[i][j] == 'B';
        }
    }
    
    while(q--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        
        ll val = get(a, b, c, d);
        cout << val << endl;
    }
}

int main() {
    task();
    return 0;
}