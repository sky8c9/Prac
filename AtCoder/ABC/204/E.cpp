#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
using Pair = pair<long long, int>;
const long long MAX = 1e18;

struct Edge {
	int v,c,d;

	Edge(int pv, int pc, int pd) {
		v = pv;
		c = pc;
		d = pd;
	}
};

long long computeT(long long curT, int c, int d) {
	return curT + c + d / (curT + 1);
}

void task() {
	int n,m;
	cin >> n >> m;

	vector<vector<Edge>> adjL(n);
	vector<long long> dist(n, MAX);
	priority_queue<Pair, vector<Pair>, greater<Pair>> q;

	while(m--) {
		int u,v,c,d;
		cin >> u >> v >> c >> d;

		u--;v--;
		adjL[u].emplace_back(v,c,d);
		adjL[v].emplace_back(u,c,d);
	}

	q.push(make_pair(0,0));
	dist[0] = 0;

	while(!q.empty()) {
		auto[t,u] = q.top(); q.pop();
		if (dist[u] != t) continue;
		if (u == n-1) {
			cout << t << endl;
			return;
		}

		for(const auto&[v,c,d] : adjL[u]) {
			long long nextT = MAX;
			long long sqrtD = sqrt(d);

			if (t > sqrtD - 1) nextT = computeT(t, c, d);
			else nextT = min(computeT(sqrtD, c, d), computeT(sqrtD + 1, c, d));

			if (nextT < dist[v]) {
				dist[v] = nextT;
				q.push(make_pair(dist[v], v));
			}
		}
	}

	cout << -1 << endl;
}

int main() {
	task();
	return 0;
}