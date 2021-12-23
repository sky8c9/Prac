#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void task() {
	int h, w, n;
	cin >> h >> w >> n;

	vector<int> rmax(h);
	vector<int> cmax(w);
	vector<int> posI(n);
	vector<int> posJ(n);
	vector<int> ans(n);
	map<int, vector<int> > cells;

	for(int i = 0; i < n; i++) {
		int r, c, a;
		cin >> r >> c >> a;
		r--;c--;

		cells[a].push_back(i);
		posI[i] = r;
		posJ[i] = c;
	}

	for(auto itr = cells.rbegin(); itr != cells.rend(); itr++) {
		for(int index : itr->second) {
			ans[index] = max(rmax[posI[index]], cmax[posJ[index]]);
		}

		for(int index : itr->second) {
			rmax[posI[index]] = max(rmax[posI[index]], ans[index] + 1);
			cmax[posJ[index]] = max(cmax[posJ[index]], ans[index] + 1);
		}
	}

	for(int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}

}

int main() {
	task();
	return 0;
}