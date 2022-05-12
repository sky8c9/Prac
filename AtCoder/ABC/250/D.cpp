#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MAX = 1e6 + 1;
void task() {
	ll n;
	cin >> n;

	vector<bool> isPrime(MAX, true);
	vector<ll> primes;
	isPrime[2] = true;
	for(int i = 2; i < MAX; i++) {
		if (isPrime[i]) {
			primes.push_back(i);

			for(int j = i; j < MAX; j += i) {
				isPrime[j] = false;
			}
		}
	}

	int ans = 0;
	int lo = 0;
	int hi = primes.size() - 1;
	while(lo < hi) {
		if (primes[lo] * primes[hi] * primes[hi] * primes[hi] > n) {
			hi--;
		} else {
			ans += hi - lo;
			lo++;
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}