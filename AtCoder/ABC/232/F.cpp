#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll MAX = 1e18;

void task() {
	ll n,x,y;
	cin >> n >> x >> y;

	vector<int> a(n);
	vector<int> b(n);
	for(int& val : a) cin >> val;
	for(int& val : b) cin >> val;

	vector<ll> dp(1 << n, MAX);
	dp[0] = 0;
	for(int s = 0; s < (1 << n); s++) {
		int setBits = __builtin_popcount(s);
		for(int nxt = 0; nxt < n; nxt++) {
			if ((s >> nxt) & 1) continue;

			int invCnt = __builtin_popcount(s >> nxt);
			ll cost = abs(a[nxt] - b[setBits]) * x + invCnt * y;
			dp[s | (1 << nxt)] = min(dp[s | (1 << nxt)], dp[s] + cost);
		}
	}

	cout << dp[(1 << n) - 1] << endl;
}

int main() {
	task();
	return 0;
}