#include <iostream>
#include <vector>
#include <string>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<string> grid;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;

		grid.push_back(s);
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int cntB = 0;

			// col check
			if (i <= n - 6) {
				for(int k = 0; k < 6; k++) {
					if (grid[i+k][j] == '#') cntB++;
				}

				if (cntB >= 4) {
					cout << "Yes" << endl;
					return;
				}
			}

			// row check
			cntB = 0;
			if (j <= n - 6) {
				for(int k = 0; k < 6; k++) {
					if (grid[i][j+k] == '#') cntB++;
				}

				if (cntB >= 4) {
					cout << "Yes" << endl;
					return;
				}
			}

			// diag1 check
			cntB = 0;
			if (i <= n - 6 && j <= n - 6) {
				for(int k = 0; k < 6; k++) {
					if (grid[i+k][j+k] == '#') cntB++;
				}

				if (cntB >= 4) {
					cout << "Yes" << endl;
					return;
				}
			}

			// diag2 check
			cntB = 0;
			if (i - 5 >= 0 && j <= n - 6) {
				for(int k = 0; k < 6; k++) {
					if (grid[i-k][j+k] == '#') cntB++;
				}

				if (cntB >= 4) {
					cout << "Yes" << endl;
					return;
				}
			}
		}
	}

	cout << "No" << endl;
}

int main() {
	task();
	return 0;
}