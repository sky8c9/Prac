#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void task() {
	int n,m;
	cin >> n >> m;

	vector<int> inDeg(n);
	vector<int> ans;
	vector<vector<int>> adjL(n);
	while(m--) {
		int u,v;
		cin >> u >> v;
		u--;v--;

		adjL[u].push_back(v);
		inDeg[v]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; i++) {
		if (inDeg[i] == 0) pq.push(i);
	}

	while(!pq.empty()) {
		int u = pq.top(); pq.pop();
		ans.push_back(u + 1);

		for(int v : adjL[u]) {
			inDeg[v]--;
			if (inDeg[v] == 0) pq.push(v);
		} 
	}

	if (ans.size() != n) {
		cout << -1 << endl;
	} else {
		for(int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
	}
}

int main() {
	task();
	return 0;
}