#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int prime_factor_counter(ll num) {
	vector<pair<ll, int>> primes;

	for(ll i = 2; i * i < num; i++) {
		if (num % i) continue;
		
		int count = 1;
		while(num % i == 0) {
			num /= i;
			count++;
		}
		primes.emplace_back(i, count);
	}

	if (num != 1) primes.emplace_back(num, 1);
	return primes.size();
}

void task() {
	ll a,b;
	cin >> a >> b;

	ll num = gcd(a, b);
	int counter = prime_factor_counter(num);
	cout << counter + 1 << endl;
}

int main() {
	task();
	return 0;
}