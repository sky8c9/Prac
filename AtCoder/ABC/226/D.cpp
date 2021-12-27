#include <iostream>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b%a, a);
}

void task() {
	int n;
	cin >> n;

	vector<pair<int,int>> pos(n);
	set<pair<int,int>> ans;

	for(int i = 0; i < n; i++) {
		cin >> pos[i].first >> pos[i].second;
	}

	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			int dx = pos[i].first - pos[j].first;
			int dy = pos[i].second - pos[j].second;
			int z = gcd(dx,dy);

			ans.insert(make_pair(dx/z, dy/z));
		}
	}

	cout << ans.size() * 2 << endl;
}

int main() {
	task();
	return 0;
}