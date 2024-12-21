#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

const int MAX = 1e6;

void task() {
    ll n;
    cin >> n;

    vector<int> p;
    vector<bool> isPrime(MAX + 1, true);
    for (ll i = 2; i*i*i <= n; i++) {
        if (isPrime[i]) {
            for (ll j = i*i; j <= n; j += i) {
                if (j > MAX) break;
                isPrime[j] = false;
            }
        }
    }

    for(int i = 2; i < MAX; i++) {
        if (isPrime[i]) p.push_back(i);
    }

    int ans = 0;
    for(int i = 0; i < p.size(); i++) {
        for(int j = i + 1; j < p.size(); j++) {
            if ((ll) p[i] * p[i] * p[j] > n) break;
            if ((ll)p[i] * p[i] * p[j] * p[j] > n) break;
            ++ans;
        }
    }

    for(int i = 0; i < p.size(); i++) {
        if (pow(p[i], 8) > n) break;
        else ++ans;
    }

    cout << ans << endl;
}

int main() {
    task();
    return 0;
}