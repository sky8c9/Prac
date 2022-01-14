#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++) {
		int x,y;
		cin >> x >> y;

		v[i] = make_pair(x,y);
	}

	double ans = 0;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			int diffx = v[i].first - v[j].first;
			int diffy = v[i].second - v[j].second;
			ans = max(ans, sqrt(diffx * diffx + diffy * diffy));
		}
	}

	cout << setprecision(12) << ans << endl;
}

int main() {
	task();
	return 0;
}