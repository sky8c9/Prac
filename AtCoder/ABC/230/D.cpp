#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void task() {
	int n,d;
	cin >> n >> d;

	vector<pair<int, int>> intervals(n);
	for(int i = 0; i < n; i++) {
		int l,r;
		cin >> l >> r;
		intervals[i].first = r;
		intervals[i].second = l;
	}

	sort(intervals.begin(), intervals.end());
	int ans = 0;
	int ptr = -1e9;
	for(auto[r,l] : intervals) {
		if (ptr + d - 1< l) {
			ans++;
			ptr = r;
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}