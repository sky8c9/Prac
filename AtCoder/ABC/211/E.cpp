#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
vector<int> didj{1,0,-1,0,1};
set<vector<string>> seen;
vector<string> grid;
int ans = 0;
int n = 0;

void dfs(int remained) {
	if (seen.count(grid)) return;
	seen.insert(grid);

	if (remained == 0) {
		ans++;
		return;
	}

	vector<pair<int, int>> cands;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (grid[i][j] != '.') continue;

			for(int k = 0; k < didj.size() - 1; k++) {
				int ni = i + didj[k];
				int nj = j + didj[k+1];

				if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
				if (grid[ni][nj] == '@') {
					cands.emplace_back(i, j);
					break;
				}
			}
		}
	}

	for(auto[i, j] : cands) {
		grid[i][j] = '@';
		dfs(remained - 1);
		grid[i][j] = '.';
	}
}

void task() {
	int k;
	cin >> n >> k;

	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;

		grid.push_back(s);
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (grid[i][j] != '.') continue;

			grid[i][j] = '@';
			dfs(k - 1);
			grid[i][j] = '.';
		}
	}

	cout << ans << endl;
}	

int  main() {
	task();
	return 0;
}