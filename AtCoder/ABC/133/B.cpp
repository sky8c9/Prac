#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n,d;
	cin >> n >> d;

	vector<vector<int>> points(n, vector<int>(d));
	for(int i = 0; i < n; i++) {
		for(int&val : points[i]) {
			cin >> val;
		}
	}

	int ans = 0;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			int total = 0;

			for(int k = 0; k < d; k++) {
				int diff = points[i][k] - points[j][k];
				total += diff * diff;
			}

			for(int k = 1; k * k <= total; k++) {
				if (k * k == total) ans++;
			}

		}
	}

	cout <<  ans << endl;
}

int main() {
	task();
	return 0;
}