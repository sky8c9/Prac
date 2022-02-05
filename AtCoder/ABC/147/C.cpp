#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

void task() {
	int n;
	cin >> n;

	unordered_map<int, unordered_set<int>> testi1(n);
	unordered_map<int, unordered_set<int>> testi0(n);
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;

		for(int j = 0; j < a; j++) {
			int x,y;
			cin >> x >> y;
			x--;

			if (y) testi1[i].insert(x);
			else testi0[i].insert(x);
		}
	}

	int ans = 0;
	for(int i = 0; i < (1 << n); i++) {
		unordered_set<int> candidates;

		for(int j = 0; j < n; j++) {
			if ((i >> j) & 1) candidates.insert(j);
		}

		bool flag = true;
		for(int candidate : candidates) {
			for(int kind : testi1[candidate]) {
				if (candidates.count(kind) == 0) {
					flag = false;
					break;
				}
			}

			for(int unkind : testi0[candidate]) {
				if (candidates.count(unkind) == 1) {
					flag = false;
					break;
				}
			}

			if (!flag) break;
		}

		if (flag) ans = max(ans, (int) candidates.size());
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}