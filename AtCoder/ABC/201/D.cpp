#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int minimax(vector<vector<int>>& val, vector<vector<int>>& memo, vector<vector<bool>>& seen, int i, int j, int h, int w) {
	if (i == h-1 && j == w-1) return 0;
	if (seen[i][j]) return memo[i][j];

	seen[i][j] = true;
	if ((i+j) & 1) { // sum is odd - Aoki turn	
		int tmp = INT_MAX;
		if (j + 1 < w) tmp = min(tmp, minimax(val,memo,seen,i,j+1,h,w) - val[i][j+1]);
		if (i + 1 < h) tmp = min(tmp, minimax(val,memo,seen,i+1,j,h,w) - val[i+1][j]);
		return memo[i][j] = tmp;
	} else { // Takahashi turn
		int tmp = INT_MIN;
		if (j + 1 < w) tmp = max(tmp, minimax(val,memo,seen,i,j+1,h,w) + val[i][j+1]);
		if (i + 1 < h) tmp = max(tmp, minimax(val,memo,seen,i+1,j,h,w) + val[i+1][j]);
		return memo[i][j] = tmp;
	}
}

void task() {
	vector<vector<int>> memo(2001, vector<int>(2001));
	vector<vector<bool>> seen(2001, vector<bool>(2001));
	int h,w;
	string s;

	// input
	cin >> h >> w;
	vector<vector<int>> val(h, vector<int>(w));
	for(int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < w; j++) {
			val[i][j] = s[j] == '+' ? 1 : -1;
		}
	}

	// output
	int ans = minimax(val,memo,seen,0,0,h,w);
	if (ans > 0) {
		cout << "Takahashi" << endl;
	} else if (ans < 0) {
		cout << "Aoki" << endl;
	} else {
		cout << "Draw" << endl;
	}
}

int main() {
	task();
	return 0;
}