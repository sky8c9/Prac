#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll MAX = 1e18;
void task() {
	ll n,l,r;
	cin >> n >> l >> r;

	vector<ll> a(n);
	vector<ll> dpL(n + 1);
	vector<ll> dpR(n + 1);

	for(ll& val : a) cin >> val;
	for(int i = 0; i < n; i++) {
		dpL[i + 1] = min(dpL[i] + a[i], l * (i + 1));
	}

	dpR[n] = min(a[n - 1], r);
	for(int i = 1; i < n; i++) {
		dpR[n - i] = min(dpR[n - i + 1] + a[n - i - 1], r * (i + 1));
	}

	ll ans = min(dpL[n], dpR[1]);
	for(int i = 1; i < n; i++) {
		ans = min(ans, dpL[i] + dpR[i + 1]);
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;

}