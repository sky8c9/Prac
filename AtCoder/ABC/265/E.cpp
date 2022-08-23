#include <iostream>
#include <vector>
#include <set>
#include <map>

const int MOD = 998244353;
using namespace std;
using ll = long long;

void task() {
	int n,m;
	cin >> n >> m;

	vector<pair<ll,ll>> dxdy;
	for(int i = 0; i < 3; i++) {
		ll x,y;
		cin >> x >> y;
		dxdy.emplace_back(x, y);
	}

	set<pair<ll, ll>> seen;
	for(int i = 0; i < m; i++) {
		ll x,y;
		cin >> x >> y;
		seen.emplace(x, y);
	}

	map<pair<ll,ll>, ll> dp;
	dp[make_pair(0, 0)] = 1;
	for(int i = 0; i < n; i++) {
		map<pair<ll, ll>, ll> tmp;

		for(auto[cur, cnt] : dp) {
			for(int j = 0; j < 3; j++) {
				pair<ll,ll> nxt = make_pair(cur.first + dxdy[j].first, cur.second + dxdy[j].second);
				if (seen.count(nxt)) continue;
				tmp[nxt] += cnt;
				tmp[nxt] %= MOD;
			}
		}

		dp = tmp; 
	}

	ll ans = 0;
	for(auto[cur, cnt] : dp) {
		ans += cnt;
		ans %= MOD;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}