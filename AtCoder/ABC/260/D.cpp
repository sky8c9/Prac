#include <iostream>
#include <vector>
#include <map>

using namespace std;

void task() {
	int n,k;
	cin >> n >> k;
	
	vector<int> ans(n, -1);
	map<int, vector<int>> piles;
	for(int i = 1; i <= n; i++) {
		int p;
		cin >> p;

		auto l = piles.lower_bound(p);
		if (l == piles.end()) piles[p].push_back(p);
		else {
			piles[p] = move(l->second);
			piles[p].push_back(p);
			piles.erase(l);
		}

		if (piles[p].size() == k) {
			for(int val : piles[p]) ans[val - 1] = i;
			piles.erase(p);
		}
	}

	for(int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}
	
}

int main() {
	task();
	return 0;
}