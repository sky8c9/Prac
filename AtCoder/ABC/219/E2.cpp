#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 4;

struct Dsu {
	vector<int> parents;
	vector<int> ranks;
	int count;

	Dsu(int n) {
		count = n;
		parents = vector<int>(n);
		ranks = vector<int>(n);

		for(int i = 0; i < n; i++) {
			parents[i] = i;
			ranks[i] = 1;
		}
	}

	int find(int cur) {
		if (cur != parents[cur]) {
			parents[cur] = find(parents[cur]);
		}
		return parents[cur];
	}

	bool merge(int a, int b) {
		int pa = find(a);
		int pb = find(b);
		if (pa == pb) return false;

		if (ranks[pa] > ranks[pb]) parents[pb] = pa;
		else {
			if (ranks[pa] == ranks[pb]) ranks[pb]++;
			parents[pa] = pb;
		}

		count--;
		return true;
	}
};

void task() {
	int encode = 0;
	int ans = 0;

	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			int pos,val;
			cin >> val;

			// encode each village position into an integer value
			pos = i * SIZE + j;
			if (val) {
				encode |= (1 << pos); 
			}
		}
	}

	for(int moat = 0; moat < (1 << (SIZE * SIZE)); moat++) {
		if ((moat & encode) == encode) { // moat pattern contains all villages
			// Set selected cell to 1
			vector grid(SIZE + 2, vector<int>(SIZE + 2));
			for(int i = 0; i < SIZE; i++) {
				for(int j = 0; j < SIZE; j++) {
					int pos = i * SIZE + j;

					if (moat >> pos & 1) {
						grid[i + 1][j + 1] = 1;
					}
				}
			}

			// Cells with same color on vertical/horizontal axis are merged together
			int n = SIZE + 2;
			Dsu uf(n*n);
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					int pos = i * n + j;

					if (i + 1 < n && grid[i][j] == grid[i+1][j]) {
						uf.merge(pos, pos + n);
					}
					if (j + 1 < n && grid[i][j] == grid[i][j+1]) {
						uf.merge(pos, pos + 1);
					}
				}
			}
			if (uf.count == 2) ans++;
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}