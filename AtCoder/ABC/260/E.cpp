#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

void task() {
	int n,m;
	cin >> n >> m;

	vector<vector<int>> val2Pos(m + 1);
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		val2Pos[a].push_back(i);
		val2Pos[b].push_back(i);
	}

	vector<int> ans(m + 1);
	map<int, set<int>> pos2Val;
	for(int i = 1, j = 1; i <= m; i++) {
		while(j <= m && pos2Val.size() < n) {
			for(int idx : val2Pos[j]) {
				pos2Val[idx].insert(j);
			}

			j++;
		}

		if (pos2Val.size() == n) {
			ans[j - i]++;
			ans[m - i + 2]--;
		}

		for(int idx : val2Pos[i]) {
			pos2Val[idx].erase(i);
			if (pos2Val[idx].size() == 0) pos2Val.erase(idx);
		}
	}

	for(int i = 1; i <= m; i++) {
		ans[i] += ans[i - 1]; 
		cout << ans[i] << " ";
	}
}

int main() {
	task();
	return 0;
}