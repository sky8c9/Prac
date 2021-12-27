#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void task() {
	int n;
	cin >> n;

	vector<int> t(n + 1);
	vector<vector<int>> a(n + 1);

	for(int i = 1; i <= n; i++) {
		int k;
		cin >> t[i] >> k;
		a[i] = vector<int>(k);
		for(int j = 0; j < k; j++) cin >> a[i][j];
	}

	ll ans = 0;
	vector<bool> preq(n + 1);
	preq[n] = true;

	for(int i = n; i > 0; i--) {
		if (preq[i]) {
			for(int j = 0; j < a[i].size(); j++) {
				preq[a[i][j]] = true;
			}
		}	
	}

	for(int i = 1; i <= n; i++) {
		if (preq[i]) {
			ans += t[i];
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}