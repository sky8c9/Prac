#include <iostream>
#include <vector>
#include <map>

using namespace std;

void task() {
	int n,q;
	cin >> n >> q;

	vector<int> a(n);
	map<int, vector<int>> m;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;

		a[i] = val;
		m[val].push_back(i+1);
	}

	for(int i = 0; i < q; i++) {
		int x,k;
		cin >> x >> k;

		if (m.count(x) == 0 || k > m[x].size()) cout << -1 << endl;
		else cout << m[x][k-1] << endl;
	}
}

int main() {
	task();
	return 0;
}