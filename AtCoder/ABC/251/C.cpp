#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

void task() {
	int n;
	cin >> n;

	unordered_set<string> seen;
	pair<int, int> ans{0, 0};
	for(int i = 1; i <= n; i++) {
		string s;
		int t;
		cin >> s >> t;

		if (seen.count(s)) continue;
		seen.insert(s);
		if (t > ans.second) {
			ans.first = i;
			ans.second = t;
		}
	}

	cout << ans.first << endl;
}

int main() {
	task();
	return 0;
}