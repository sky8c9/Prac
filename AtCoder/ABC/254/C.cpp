#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>> v(k);
	vector<int> pos(k, 0);
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;

		v[i % k].push_back(val);
	}

	for(int i = 0; i < k; i++) {
		sort(v[i].begin(), v[i].end());
	}

	int prev = 0;
	for(int i = 0; i < n; i++) {
		int curVal = v[i % k][pos[i % k]++];

		if (curVal < prev) {
			cout << "No" << endl;
			return;
		}

		prev = curVal;
	}

	cout << "Yes" << endl;
}

int main() {
	task();
	return 0;
}