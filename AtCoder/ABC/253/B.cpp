#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void task() {
	int h,w;
	cin >> h >> w;

	vector<string> s(h);
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = -1;
	for(int i = 0; i < h; i++) {
		cin >> s[i];

		for(int j = 0; j < s[i].length(); j++) {
			if (s[i][j] == 'o') {
				if (x1 == -1) {
					x1 = i;
					y1 = j;
				} else {
					x2 = i;
					y2 = j;
				}
			}
		}
	}

	cout << (abs(x1-x2) + abs(y1-y2)) << endl;

}

int main() {
	task();
	return 0;
}