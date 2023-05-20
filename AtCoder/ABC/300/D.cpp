#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
    ll n;
    cin >> n;

    int m = (int) sqrt(n);
    vector<bool> isPrime(m + 1, true);
    vector<ll> primes;
    for(int p = 2; p * p <= m; p++) {
        if (isPrime[p] == true) {
            for(int i = p * p; i <= m; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for(int i = 2; i <= m; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    int ans = 0;
    for(int i = 0; i < primes.size(); i++) {
        for(int j = i + 1; j < primes.size(); j++) {
            if (primes[i] * primes[i] * primes[j] > n) break;
            for(int k = j + 1; k < primes.size(); k++) {
                if (primes[i] * primes[i] * primes[j] * primes[k] > n) break;
                if (primes[i] * primes[i] * primes[j] * primes[k] * primes[k] > n) break;
                ++ans;
            }
        }
    }
    
    cout << ans << endl;
}

int main() {
    task();
    return 0;
}