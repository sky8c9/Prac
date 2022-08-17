#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int h1,w1;
	cin >> h1 >> w1;

	vector<vector<int>> m1(h1, vector<int>(w1));
	for(int i = 0; i < h1; i++) {
		for(int j = 0; j < w1; j++) {
			cin >> m1[i][j];
		}
	}

	int h2,w2;
	cin >> h2 >> w2;
	vector<vector<int>> m2(h2, vector<int>(w2));
	for(int i = 0; i < h2; i++) {
		for(int j = 0; j < w2; j++) {
			cin >> m2[i][j];
		}
	}

	for(int i = 0; i < (1 << h1); i++) {
		for(int j = 0; j < (1 << w1); j++) {
			vector<int> r, c;
			for(int k = 0; k < h1; k++) {
				if (((i >> k) & 1) == 0) r.push_back(k);
			}
			
			for(int k = 0; k < w1; k++) {
				if (((j >> k) & 1) == 0) c.push_back(k);
			}

			if (r.size() != h2 || c.size() != w2) continue;
			bool flag = true;
			for(int k = 0; flag && k < h2; k++) {
				for(int l = 0; flag && l < w2; l++) {
					if (m1[r[k]][c[l]] != m2[k][l]) flag = false;
				}
			}

			if (flag) {
				cout << "Yes" << endl;
				return;
			}
		}
	}

	cout << "No" << endl;
}

int main() {
	task();
	return 0;
}