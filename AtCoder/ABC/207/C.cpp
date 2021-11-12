#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const double DIFF = 0.5;

void task() {
	int n;
	cin >> n;

	vector<double> lo(n);
	vector<double> hi(n);
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t >> lo[i] >> hi[i];

		if (t == 2 || t == 4) hi[i] -= DIFF;
		if (t == 3 || t == 4) lo[i] += DIFF;
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			double l = max(lo[i], lo[j]);
			double r = min(hi[i], hi[j]);

			if (l <= r) ans++;
		}
	}
	
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}