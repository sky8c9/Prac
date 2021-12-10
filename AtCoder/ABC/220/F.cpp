#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int subNodeCount(int u, int p, int depth, ll& sum, vector<int>& counter, vector<vector<int>>& adjL) {
	for(int v : adjL[u]) {
		if (v == p) continue;
		sum += depth;
		counter[u] += subNodeCount(v,u,depth+1,sum,counter,adjL);
	}

	return counter[u];
}

void findSumLength(int u, int p, vector<int>& counter, vector<ll>& sumLength, vector<vector<int>>& adjL) {
	for(int v : adjL[u]) {
		if (v == p) continue;
		sumLength[v] = sumLength[u] + counter.size() - 2 * counter[v];
		findSumLength(v,u,counter,sumLength,adjL);
	}
}

void task() {
	int n;
	cin >> n;

	vector<vector<int>> adjL(n);
	for(int i = 0; i < n - 1; i++) {
		int u,v;
		cin >> u >> v;
		u--;v--;

		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	vector<int> counter(n, 1);
	vector<ll> sumLength(n);
	subNodeCount(0,-1,1,sumLength[0],counter,adjL);
	findSumLength(0,-1,counter,sumLength,adjL);
	
	for(int i = 0; i < n; i++) {
		cout << sumLength[i] << endl;
	}
}

int main() {
	task();
	return 0;
}
