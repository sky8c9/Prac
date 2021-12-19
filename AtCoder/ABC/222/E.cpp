#include <iostream>
#include <vector>

using namespace std;
const int MOD = 998244353;

vector<vector<pair<int,int>>> adjL;
vector<int> cnt;

bool dfs(int u, int e, int parent) {
	if (u == e) return true;

	for(auto&[v,id] : adjL[u]) {
		if (v == parent) continue;

		if (dfs(v, e, u)) {
			cnt[id]++;
			return true;
		}
	}

	return false;
}

void task() {
	int n,m,k;
	cin >> n >> m >> k;

	adjL = vector<vector<pair<int,int>>>(n);
	cnt = vector<int>(n - 1);
	vector<int> a(m);

	for(int& val : a) {
		cin >> val;
		val--;
	}

	for(int i = 0; i < n - 1; i++) {
		int u,v;
		cin >> u >> v;
		u--;v--;

		adjL[u].push_back(make_pair(v, i));
		adjL[v].push_back(make_pair(u, i));
	}

	for(int i = 0; i < m - 1; i++) {
		dfs(a[i],a[i+1],-1);
	}

	int sum = 0;
	for(int val : cnt) sum += val;
	if (sum + k < 0 || (sum + k) % 2 != 0) {
		cout << 0 << endl;
		return;
	}

	int red = (sum + k) / 2;
	vector<int> dp(red + 1);
	dp[0] = 1;
	for(int val : cnt) {
		for(int d = red - val; d >= 0; d--) {
			dp[d + val] = (dp[d + val] + dp[d]) % MOD;
		}
	}

	cout << dp[red] << endl;
}

int main() {
	task();
	return 0;
}