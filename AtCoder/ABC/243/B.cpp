#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void task() {
	int n;
	cin >> n;

	unordered_map<int, unordered_set<int>> m;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;

		m[a].insert(i);
	}

	int ans1 = 0;
	int ans2 = 0;
	for(int i = 0; i < n; i++) {
		int b;
		cin >> b;

		ans2 += m[b].size();
		if (m[b].count(i) != 0) {
			ans1++;
			ans2--;
		}
	}

	cout << ans1 << endl;
	cout << ans2 << endl;
}

int main() {
	task();
	return 0;
}