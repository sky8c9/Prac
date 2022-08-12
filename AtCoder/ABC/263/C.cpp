#include <iostream>
#include <vector>

using namespace std;

void dfs(int n, int m, int cur, vector<int>& v) {
	if (v.size() == n) {
		for(int val : v) {
			cout << val << " ";
		}
		cout << endl;
	}

	for(int i = cur; i <= m; i++) {
		v.push_back(i);
		dfs(n,m,i + 1,v);
		v.pop_back();
	}
}

void task() {
	int n,m;
	cin >> n >> m;
	vector<int> v;
	dfs(n,m,1,v);
}

int main() {
	task();
	return 0;
}