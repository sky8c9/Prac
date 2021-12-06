#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
const int MAX = 1e9 + 1;

struct Edge {
	int v;
	int id;

	Edge(int pv, int pid) {
		v = pv;
		id = pid;
	}
};

unordered_set<int> bfs(vector<vector<Edge>>& adjL, int excludeId) {
	int n = adjL.size();
	vector<int> prev(n, -1);
	vector<int> edgeIDs(n, -1);
	vector<int> dist(n, MAX);

	// build shortest path from 0 -> n-1
	queue<int> q;
	q.push(0);
	dist[0] = 0;

	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto&[v, id] : adjL[u]) {
			if (dist[v] != MAX || id == excludeId) continue;
			dist[v] = dist[u] + 1;
			prev[v] = u;
			edgeIDs[v] = id;
			q.push(v);
		}
	}

	// No Path
	unordered_set<int> path;
	if (dist[n-1] == MAX) return path;

	// Build edge id of shortest path
	int cur = n - 1;
	while(cur != 0) {
		path.insert(edgeIDs[cur]);
		cur = prev[cur];
	}

	return path;
}

void printAns(vector<int>& ans) {
	for(int val : ans) {
		cout << val << endl;
	}
}

void task() {
	int n,m;
	cin >> n >> m;
	vector<int> ans(m);
	vector<vector<Edge>> adjL(n);

	for(int i = 0; i < m; i++) {
		int s,t;
		cin >> s >> t;
		s--;t--;

		adjL[s].push_back(Edge(t, i));
	}

	unordered_set<int> path = bfs(adjL, -1);
	int shortest = path.empty() ? -1 : path.size();
	fill(ans.begin(), ans.end(), shortest);

	if (shortest == -1) {
		printAns(ans);
	} else {
		for(int i = 0; i < m; i++) {
			if (path.count(i) == 0) continue;
			unordered_set<int> pathExcludeI = bfs(adjL, i);
			ans[i] = pathExcludeI.empty() ? -1 : pathExcludeI.size();
		}

		printAns(ans);
	}
}

int main() {
	task();
	return 0;
}