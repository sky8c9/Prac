#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void task() {
    ll n, t;
    cin >> n >> t;

    vector<ll> a(n);
    vector<ll> sum(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i] += a[i];
        sum[i] += i == 0 ? 0 : sum[i - 1];
    }

    ll r = t % sum[n - 1];
    auto itr = lower_bound(sum.begin(), sum.end(), r);
    
    int index = itr - sum.begin();
    ll seconds = index == 0 ? r : r - sum[index - 1];

    cout << index + 1 << " " << seconds << endl;
}

int main() {
    task();
    return 0;
}
