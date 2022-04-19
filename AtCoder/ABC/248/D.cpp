#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void task() {
	int n;
	cin >> n;

	unordered_map<int, vector<int>> m;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;

		m[a].push_back(i);
	}

	int q;
	cin >> q;
	for(int i = 0; i < q; i++) {
		int l,r,x;
		cin >> l >> r >> x;
		l--;r--;

		int pL = lower_bound(m[x].begin(), m[x].end(), l) - m[x].begin();
		int pR = upper_bound(m[x].begin(), m[x].end(), r) - m[x].begin();
		cout << pR - pL << endl;
	}
}

int main() {
	task();
	return 0;
}