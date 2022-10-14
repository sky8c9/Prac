#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n,m;
	cin >> n >> m;
	vector<vector<bool>> meet(n + 1, vector<bool>(n + 1, false));
	for(int i = 0; i < m; i++) {
		int k;
		cin >> k;
		vector<int> x(k);
		for(int&val : x) cin >> val;
		for(int j = 0; j < k; j++) {
			for(int l = j + 1; l < k; l++) {
				meet[x[j]][x[l]] = true;
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if (!meet[i][j]) {
				cout << "No" << endl;
				return;
			}
		}
	}
	

	cout << "Yes" << endl;
}

int main() {
	task();
	return 0;
}