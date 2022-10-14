#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
void task() {
	int n, m;
	cin >> n >> m;

	vector<set<int>> seen(m + 1);
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (a > n) continue;
		int s = a >= 0 ? 1 : (-a + i) / (i + 1);
		int e = min(m, (n - a) / (i + 1));
		for(int j = s; j <= e; j++) {
			seen[j].insert(a + j * (i + 1));
		}
	}

	for(int i = 1; i <= m; i++) {
		int ans = 0;
		while(seen[i].count(ans)) ++ans;
		cout << ans << endl;
	}
}

int main() {
	task();
	return 0;
}