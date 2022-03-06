#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

void task() {
	ll n,k;
	cin >> n >> k;

	vector<ll> a(n);
	for(ll& val : a) cin >> val;

	unordered_map<int, ll> indexing;
	vector<ll> total;
	indexing[0] = 0;
	total.push_back(0);

	ll sum = 0;
	int index = 0;
	int cStart = 0;
	while(true) {
		sum += a[sum % n];
		total.push_back(sum);

		if (indexing.find(sum % n) != indexing.end()) {
			cStart = indexing[sum % n];
			break;
		}

		indexing[sum % n] = ++index;
	}

	if (k <= total.size()) {
		cout << total[k] << endl;
		return;
	}

	ll ans = 0;
	k -= cStart + 1;
	ll cycleS = total[total.size() - 1] - total[cStart];
	ll q = k / (total.size() - cStart - 1);
	ll r = k % (total.size() - cStart - 1);
	ans += q * cycleS + total[cStart + r + 1];

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}