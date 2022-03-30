#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void task() {
	int n,m;
	cin >> n >> m;

	vector<pair<int, int>> chocoBars(n);
	vector<pair<int, int>> boxes(m);

	for(int i = 0; i < n; i++) cin >> chocoBars[i].first;
	for(int i = 0; i < n; i++) cin >> chocoBars[i].second;
	for(int i = 0; i < m; i++) cin >> boxes[i].first;
	for(int i = 0; i < m; i++) cin >> boxes[i].second;

	sort(chocoBars.rbegin(), chocoBars.rend());
	sort(boxes.rbegin(), boxes.rend());
	multiset<int> h;
	int j = 0;
	for(int i = 0; i < n; i++) {
		while(j < m && boxes[j].first >= chocoBars[i].first) {
			h.insert(boxes[j].second);
			++j;
		}

		auto itr = h.lower_bound(chocoBars[i].second);
		if (itr == h.end()) {
			cout << "No" << endl;
			return;
		}

		h.erase(itr);
	}

	cout << "Yes" << endl;
}

int main() {
	task();
	return 0;
}