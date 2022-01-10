#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int n,k;
	cin >> n >> k;

	vector<int> v(n);
	int range = min(k, n);
	int ans = 0;

	for(int i = 0; i < n; i++) cin >> v[i];
	for(int i = 0; i <= k; i++) {
		for(int j = 0; j <= k ; j++) {
			if (i + j > range || i + j == 0) continue;
			int remain = k - i - j;
			int sum = 0;
			vector<int> values;

			for(int l = 0; l < i; l++) {
				sum += v[l];
				values.push_back(v[l]);
			}

			for(int r = 0; r < j; r++) {
				sum += v[n-1-r];
				values.push_back(v[n-1-r]);
			}

			sort(values.begin(), values.end());
			int size = values.size();
			int len = min(remain, size);
			for(int l = 0; l < len; l++) {
				if (values[l] < 0) sum -= values[l];
			}

			ans = max(ans, sum);
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}