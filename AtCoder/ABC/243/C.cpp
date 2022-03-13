#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
void task() {
	int n;
	cin >> n;

	vector<pair<int, int>> pos;
	unordered_map<int, int> leftDirMax;
	unordered_map<int, int> rightDirMin;
	for(int i = 0; i < n; i++) {
		int x,y;
		cin >> x >> y;
		pos.emplace_back(x, y);
		leftDirMax[y] = -1;
		rightDirMin[y] = 1e9+1;
	}

	string s;
	cin >> s;
	for(int i = 0; i < n; i++) {
		auto[x,y] = pos[i];

		if (s[i] == 'L') {
			leftDirMax[y] = max(leftDirMax[y], x);
		} else {
			rightDirMin[y] = min(rightDirMin[y], x);
		}

		if (leftDirMax[y] > rightDirMin[y]) {
			cout << "Yes" << endl;
			return;
		}
	}

	cout << "No" << endl;
}

int main() {
	task();
	return 0;
}