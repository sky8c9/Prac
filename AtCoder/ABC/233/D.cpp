#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

void task() {
	int n;
	ll k;
	cin >> n >> k;

	vector<int> A(n);
	map<ll, ll> m;
	m[0] = 1;

	ll sum = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> A[i];
		sum += A[i];
		ans += m[sum - k];
		m[sum]++;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}