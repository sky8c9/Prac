#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const long long mod = 1e9 + 7;

struct Edge {
	int to;
	long long w;

	Edge(int v, long long weight) {
		to = v;
		w = weight;
	}
};

void task() {
	int n;
	long long ans = 0;
	cin >> n;

	vector<vector<Edge>> adjL(n);
	vector<long long> dist(n,-1);
	queue<int> q;

	for(int i = 0; i < n - 1; i++) {
		int u,v;
		long long w;
		cin >> u >> v >> w;
		adjL[u-1].emplace_back(v-1,w);
		adjL[v-1].emplace_back(u-1,w);
	}

	q.push(0);
	dist[0] = 0;
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		for(int i = 0; i < adjL[cur].size(); i++) {
			int v = adjL[cur][i].to;
			long long w = adjL[cur][i].w;
			if (dist[v] != -1) continue;

			dist[v] = dist[cur] ^ w; 
			q.push(v);
		}
	}

	for(int i = 0; i < 60; i++) {
		vector<int> cnt(2);

		for(int v = 0; v < n; v++) {
			cnt[dist[v] >> i & 1]++;
		}

		ans += (1ll << i) % mod * cnt[0] % mod * cnt[1] % mod;
		ans %= mod;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}