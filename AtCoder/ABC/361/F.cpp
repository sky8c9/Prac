#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void task() {
    ll n;
    cin >> n;

    int mx = 60;
    ll ans = 0;
    
    vector<ll> cnt(mx);
    for(int b = mx - 1; b >= 2; b--) {
        auto findA = [&]() -> ll {
            int lo = 1;
            int hi = 1e9;

            while(lo < hi) {
                int mid = lo + (hi - lo) / 2 + 1;

                ll nn = n;
                for(int i = 0; i < b; i++) nn /= mid;

                if (nn) lo = mid;
                else hi = mid - 1; 
            }

            return lo - 1;
        };

        cnt[b] = findA();
        for(int mul = 2*b; mul < mx; mul += b) {
            cnt[b] -= cnt[mul];
        }
        
        ans += cnt[b];
    }

    cout << ans + 1 << endl;
}

int main() {
    task();
    return 0;
}