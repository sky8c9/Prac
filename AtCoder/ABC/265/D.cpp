#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
bool helper(vector<ll>& a, int s, int e, ll p, ll q) {
	for(int i = s; i <= e; i++) {
		if (p < 0 || q < 0) break;
		if (p > 0) p -= a[i];
		else if (q > 0) q -= a[i];
		if (q == 0) return true;
	}
	return false;
}

void task() {
	ll n,p,q,r;
	cin >> n >> p >> q >> r;

	ll sum = p + q + r;
	ll cur = 0;
	vector<ll> a(n);
	for(ll& val : a) cin >> val;
	for(int i = 0, j = 0; j < n; j++) {
		cur += a[j];
		while(cur > sum) cur -= a[i++];
		if (cur == sum) {
			if (helper(a, i, j, p, q)) {
				cout << "Yes" << endl;
				return;
			}
		}
	}

	cout << "No" << endl;
}

int main() {
	task();
	return 0;
}