#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<pair<int, int>> intervals;
	for(int i = 0; i < n; i++) {
		int l,r;
		cin >> l >> r;

		intervals.emplace_back(l, r);
	}

	sort(intervals.begin(), intervals.end());
	pair<int, int> cur = intervals[0];
	for(int i = 1; i < n; i++) {
		if (intervals[i].first > cur.second) {
			cout << cur.first << " " << cur.second << endl;
			cur = intervals[i];
		} else {
			cur.second = max(cur.second, intervals[i].second);
		}
	}

	cout << cur.first << " " << cur.second << endl;
}

int main() {
	task();
	return 0;
}