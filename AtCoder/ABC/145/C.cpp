#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
void task() {
	int n;
	cin >> n;

	vector<pair<int,int>> coords;
	vector<int> ordering;
	double ans;
	int cnt = 0;

	for(int i = 0; i < n; i++) {
		int x,y;
		cin >> x >> y;

		coords.emplace_back(x,y);
		ordering.push_back(i);
	}

	do {
		cnt++;
		for(int i = 0; i < n - 1; i++) {
			int dx = coords[ordering[i]].first - coords[ordering[i+1]].first;
			int dy = coords[ordering[i]].second - coords[ordering[i+1]].second;
			ans += sqrt(dx*dx + dy*dy);
		}
	} while (next_permutation(ordering.begin(), ordering.end()));

	printf("%.6f\n", ans/cnt);
}

int main() {
	task();
	return 0;
}