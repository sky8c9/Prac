#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n,m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	int row = (grid[0][0] + 6) / 7;
	int col = (grid[0][0] - 1) % 7 + 1;

	if (col + m > 8) {
		cout << "No" << endl;
		return;
	}

	for(int i = 0; i < n; i++) {
		if (i > 0 && grid[i][0] - grid[i-1][0] != 7) {
			cout << "No" << endl;
			return;
		}

		for(int j = 1; j < m; j++) {
			if (grid[i][j] - grid[i][j-1] != 1) {
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