#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll dfs(vector<ll>& a, int l, int r, int len) {
    if (l + 1 == r || len == -1) return 0;
    
    int s = l;
    int e = r;
    while(s < e) {
        int mid = s + (e - s) / 2;
        int ibit = a[mid] >> len & 1;

        if (ibit) e = mid;
        else s = mid + 1;
    }

    if (e == l || s == r) return dfs(a, l, r, len - 1);
    else return min(dfs(a, l, s, len - 1), dfs(a, s, r, len - 1)) | (1 << len);
}

void task() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for(ll& val : a) cin >> val;

    sort(a.begin(), a.end());
    ll ans = dfs(a, 0, a.size(), 29);
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}