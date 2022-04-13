#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

void task() {
	int h,w,n;
	cin >> h >> w >> n;

	int sx,sy,gx,gy;
	cin >> sx >> sy >> gx >> gy;

	map<int, set<int>> colMap;
	map<int, set<int>> rowMap;
	map<pair<int,int>, bool> seen;
	for(int i = 0; i < n; i++) {
		int x,y;
		cin >> x >> y;

		rowMap[x].insert(y);
		colMap[y].insert(x);		
	}

	int d = 0;
	queue<pair<int, int>> q;
	q.push({sx, sy});
	seen[{sx, sy}] = true;
	while(!q.empty()) {
		int sz = q.size();

		while(sz--) {
			const auto[i,j] = q.front(); q.pop();
			if (i == gx && j == gy) {
				cout << d << endl;
				return;
			}

			auto nJ = rowMap[i].lower_bound(j);
			auto nI = colMap[j].lower_bound(i);
			if (rowMap[i].size() > 0 && nJ != rowMap[i].end() && !seen[{i, *nJ - 1}]) {
				seen[{i, *nJ - 1}] = true;
				q.push({i, *nJ - 1});
			}

			if (rowMap[i].size() > 0 && nJ != rowMap[i].begin() && !seen[{i, *prev(nJ) + 1}]) {
				seen[{i, *prev(nJ) + 1}] = true;
				q.push({i, *--nJ + 1});
			}

			if (colMap[j].size() > 0 && nI != colMap[j].end() && !seen[{*nI - 1, j}]) {
				seen[{*nI - 1, j}] = true;
				q.push({*nI - 1, j});
			}

			if (colMap[j].size() > 0 && nI != colMap[j].begin() && !seen[{*prev(nI) + 1, j}]) {
				seen[{*prev(nI) + 1, j}] = true;
				q.push({*--nI + 1, j});
			}

		}

		d++;
	}


	cout << -1 << endl;
}

int main() {
	task();
}