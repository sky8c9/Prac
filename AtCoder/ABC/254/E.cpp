#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void task() {
	int n,m;
	cin >> n >> m;

	vector<vector<int>> adjL(n + 1);
	for(int i = 0; i < m; i++) {
		int u,v;
		cin >> u >> v;

		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		int x,k;
		cin >> x >> k;

		queue<int> q;
		vector<bool> seen(n+1);
		int ans = x;

		q.push(x);
		seen[x] = true;
		while(!q.empty() && k--) {
			int sz = q.size();

			while(sz--) {
				int u = q.front(); q.pop();

				for(int v : adjL[u]) {
					if (!seen[v]) {
						ans+=v;
						q.push(v);
						seen[v] = true;
					}
				}
			}
		}

		cout << ans << endl;
	}
}

int main() {
	task();
	return 0;
}