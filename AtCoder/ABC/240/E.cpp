#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e6;
vector<int> L;
vector<int> R;
vector<vector<int>> adjL;
int id = 0;

void findLeaveId(int u, int p) {
	if (p != -1 && adjL[u].size() == 1) {
		++id;
		L[u] = id;
		R[u] = id;
		return;
	}

	for(int v : adjL[u]) {
		if (v == p) continue;
		findLeaveId(v, u);
	}
}

pair<int,int> findINodeId(int u, int p) {
	for(int v : adjL[u]) {
		if (v == p) continue;
		auto[mn,mx] = findINodeId(v, u);
		L[u] = min(L[u], mn);
		R[u] = max(R[u], mx);
	}

	return make_pair(L[u],R[u]);
}

void printAns() {
	for(int i = 1; i < L.size(); i++) {
		cout << L[i] << " " << R[i] << endl;
	}
}

void task() {
	int n;
	cin >> n;

	adjL = vector<vector<int>>(n + 1);
	L = vector<int>(n + 1, MAX);
	R = vector<int>(n + 1);

	for(int i = 0; i < n - 1; i++) {
		int u,v;
		cin >> u >> v;

		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	findLeaveId(1,-1);
	findINodeId(1,-1);
	printAns();
}

int main() {
	task();
	return 0;
}