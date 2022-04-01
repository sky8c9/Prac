#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Component {
	vector<int> nodes;
	vector<int> edges;

	void addV(int v) {
		nodes.push_back(v);
	}

	void addE(int e) {
		edges.push_back(e);
	}
};

// Kosaraju
struct Scc { 
	int n;
	vector<int> gid;
	vector<vector<int>> adjL;
	vector<vector<int>> radjL;
	vector<Component> comps;
	deque<int> timeStamp;

	Scc(int sz, vector<vector<int>>& in, vector<vector<int>>& rin) {
		n = sz;
		adjL = in;
		radjL = rin;
		gid = vector<int>(n);
	}

	void build() {
		forwardPass();
		backwardPass();

		for(int u = 0; u < adjL.size(); u++) {
			for(int v : adjL[u]) {
				int pu = gid[u];
				int pv = gid[v];

				if (pu == pv) continue;
				comps[pu].addE(pv);
			}
		}
	}

	void dfsTimeStamp(int u, vector<vector<int>>& nb, vector<bool>& seen) {
		seen[u] = true;

		for(int v : nb[u]) {
			if (seen[v]) continue;
			dfsTimeStamp(v, nb, seen);
		}

		timeStamp.push_back(u);
	}

	void dfsComp(int u, vector<vector<int>>& nb, vector<bool>& seen) {
		seen[u] = true;
		gid[u] = comps.size() - 1;
		comps.back().addV(u);

		for(int v : nb[u]) {
			if (seen[v]) continue;
			dfsComp(v, nb, seen);
		}
	}

	void forwardPass() {
		vector<bool> seen(n);

		for(int u = 0; u < n; u++) {
			if (seen[u]) continue;
			dfsTimeStamp(u, adjL, seen);
		}
	}

	void backwardPass() {
		vector<bool> seen(n);

		while(!timeStamp.empty()) {
			int u = timeStamp.back(); timeStamp.pop_back();
			if (seen[u]) continue;

			Component c;
			comps.push_back(c);
			dfsComp(u, radjL, seen);
		}
	}
};

void task() {
	int n,m;
	cin >> n >> m;

	vector<vector<int>> adjL(n);
	vector<vector<int>> radjL(n);
	for(int i = 0; i < m; i++) {
		int u,v;
		cin >> u >> v;
		u--;v--;
		adjL[u].push_back(v);
		radjL[v].push_back(u);
	}

	Scc c(n, adjL, radjL);
	c.build();

	int ans = 0;
	vector<bool> loop(c.comps.size());
	for(int i = loop.size() - 1; i >= 0; i--) {
		int cnt = c.comps[i].nodes.size();

		if (cnt > 1) {
			ans += cnt;
			loop[i] = true;
		} else {
			for(int outer : c.comps[i].edges) {
				if (loop[outer]) {
					loop[i] = true;
					break;
				}
			}

			ans += loop[i];
		} 
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}