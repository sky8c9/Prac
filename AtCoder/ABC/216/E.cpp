#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;
long long sum(ll start, ll end) {
	return (start + end) * (end - start + 1) / 2;
}

void task() {
	ll n,k;
	cin >> n >> k;

	vector<ll> a(n);
	for(ll& val : a) cin >> val;
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());

	ll ans = 0;
	for(int i = 0; i < n && k > 0; i++) {
		ll nextEle = i == n - 1 ? 0 : a[i+1];
		ll diff = a[i] - nextEle;
		long long eleCnt = diff * (i + 1);

		if (eleCnt <= k) {
			ans += sum(a[i] - diff + 1, a[i]) * (i + 1);
			k -= eleCnt;
		} else {
			int q = k / (i+1);
			int r = k % (i+1);

			ans += sum(a[i] - q + 1, a[i]) * (i + 1);
			ans += (a[i] - q) * r;
			k = 0;
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}