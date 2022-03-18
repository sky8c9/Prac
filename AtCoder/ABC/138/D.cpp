#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> ans;
vector<vector<int>> adjL;

void dfs(int u, int p, ll sum) {
	for(int v : adjL[u]) {
		if (v == p) continue;
		ans[v] += sum;
		dfs(v, u, ans[v]);
	}
}

void task() {
	int n,q;
	cin >> n >> q;;


	adjL = vector<vector<int>>(n);
	for(int i = 0; i < n - 1; i++) {
		int a,b;
		cin >> a >> b;
		a--;b--;

		adjL[a].push_back(b);
		adjL[b].push_back(a);
	}

	ans = vector<ll>(n);
	for(int i = 0; i < q; i++) {
		int p,x;
		cin >> p >> x;
		p--;

		ans[p]+=x;
	}

	dfs(0,-1,ans[0]);
	for(int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}

	cout << endl;
}

int main() {
	task();
	return 0;
}