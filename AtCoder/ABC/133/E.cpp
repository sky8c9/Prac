#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll ans;
int n, k;
vector<vector<int>> adjL;

void dfs(int u, int p) {
	int color = k;
	if (p == -1) color--;
	else color-=2;

	for(int v : adjL[u]) {
		if (v == p) continue;
		ans *= color;
		ans %= MOD;
		dfs(v, u);
		color--;
	}
}

void task() {
	cin >> n >> k;
	adjL = vector<vector<int>>(n);
	for(int i = 0; i < n - 1; i++) {
		int a,b;
		cin >> a >> b;
		a--;b--;

		adjL[a].push_back(b);
		adjL[b].push_back(a);
	}

	ans = k;
	dfs(0,-1);
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}
