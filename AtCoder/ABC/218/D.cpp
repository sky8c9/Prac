#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void task() {
	int n;
	cin >> n;
	vector<pair<int,int>> coord(n);

	for(auto&[x,y] : coord) {
		cin >> x >> y;
	}

	sort(coord.begin(), coord.end());
	int ans = 0;
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			auto[x1,y1] = coord[i];
			auto[x2,y2] = coord[j];

			if (x1 < x2 && y1 < y2) {
				bool foundUR = binary_search(coord.begin(), coord.end(), make_pair(x1,y2));
				bool foundLL = binary_search(coord.begin(), coord.end(), make_pair(x2,y1));
				if (foundUR && foundLL) ans++;
			}
		}
	}
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}