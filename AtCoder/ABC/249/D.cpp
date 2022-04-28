#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long;

const int MAX = 2e5 + 1;
void task() {
	int n;
	cin >> n;

	vector<ll> freq(MAX);
	for(int i = 0; i < n; i++) {
		ll val; cin >> val;
		freq[val]++;
	}

	ll ans = 0;
	for(int j = 1; j < MAX; j++) {
		for(int k = 1; j * k < MAX; k++) {
			ans += freq[j] * freq[k] * freq[j * k];
		}
	}

	cout << ans << endl;
}


int main() {
	task();
	return 0;
}