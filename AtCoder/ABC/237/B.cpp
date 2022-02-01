#include <iostream>
#include <vector>

using namespace std;
void task() {
	int h,w;
	cin >> h >> w;

	vector<vector<int>> ans(w);
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			int val;
			cin >> val;
			ans[j].push_back(val);
		}
	}

	for(int i = 0; i < w; i++) {
		for(int j = 0; j < h; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	task();
	return 0;
}