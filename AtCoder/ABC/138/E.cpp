#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void task() {
	string s,t;
	cin >> s >> t;

	int n = s.length();
	vector<vector<int>> pos(26);
	for(int i = 0; i < n; i++) {
		pos[s[i] - 'a'].push_back(i);
	}

	ll ans = 0;
	int cur = 0;
	for(char c : t) {
		int index = c - 'a';
		if (pos[index].size() == 0) {
			cout << "-1" << endl;
			return;
		}

		auto next = lower_bound(pos[index].begin(), pos[index].end(), cur);
		if (next == pos[index].end()) {
			ans += n;
			cur = pos[index][0];
		} else {
			cur = *next;
		}

		cur += 1;
	}

	cout << ans + cur << endl;
}

int main() {
	task();
	return 0;
}