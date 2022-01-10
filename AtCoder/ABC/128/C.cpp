#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n,m;
	cin >> n >> m;

	int ans = 0;
	vector<vector<int>> bulb(m);
	for(int i = 0; i < m; i++) {
		int k;
		cin >> k;

		bulb[i].resize(k);
		for(int j = 0; j < k; j++) {
			cin >> bulb[i][j];
			bulb[i][j]--;
		}
	}

	vector<int> p(m);
	for(int i = 0; i < m ;i++) cin >> p[i];
	for(int i = 0; i < (1 << n); i++) {
		bool flag = true;

		for(int j = 0; j < m; j++) {
			int cnt = 0;

			for(int sid : bulb[j]) {
				cnt += (i >> sid) & 1;
			}

			if (cnt % 2 != p[j]) {
				flag = false;
				break;
			}
		}

		if (flag) ans++;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}