#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void task() {
	int n,k;
	cin >> n >> k;

	vector<pair<int, int> > coords(n);
	vector<vector<bool>> seen(n, vector<bool>(n));
	for(int i = 0; i < n; i++) {
		cin >> coords[i].first;
		cin >> coords[i].second;
	}

	if (k == 1) {
		cout << "Infinity" << endl;
		return;
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if (seen[i][j]) continue;

			vector<int> group;
			group.push_back(i);
			group.push_back(j);
			for(int k = j + 1; k < n; k++) {
				ll dxKI = coords[k].first - coords[i].first;
				ll dxKJ = coords[k].first - coords[j].first;

				ll dyKI = coords[k].second - coords[i].second;
				ll dyKJ = coords[k].second - coords[j].second;

				bool flag = dyKI * dxKJ == dyKJ * dxKI;
				if (flag) group.push_back(k);
			}

			if (group.size() >= k) ans++;
			for(int k = 0; k < group.size(); k++) {
				for(int l = k + 1; l < group.size(); l++) {
					seen[group[k]][group[l]] = true;
				}
			}

		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}