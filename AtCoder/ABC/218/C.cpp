#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void rotate(vector<vector<char>>& in) {
	int n = in.size();
	for(int i = 0; i < n/2 ; i++) {
		for(int j = i ; j < n - 1 - i; j++) {
			int tmp = in[i][j];

			in[i][j] = in[n-1-j][i];
			in[n-1-j][i] = in[n-1-i][n-1-j];
			in[n-1-i][n-1-j] = in[j][n-1-i];
			in[j][n-1-i] = tmp;
		}
	}
}

pair<pair<int,int>,int> getInfo(const vector<vector<char>>& in) {
	int initI = -1;
	int initJ = -1;
	int count = 0;

	for(int i = 0; i < in.size(); i++) {
		for(int j = 0; j < in[0].size(); j++) {
			if (in[i][j] == '#') {
				if (initI == -1 && initJ == -1) {
					initI = i;
					initJ = j;
				}

				count++;
			}
		}
	}

	return make_pair(make_pair(initI,initJ), count);
}

void readData(vector<vector<char>>& in, int n) {
	for(int line = 0; line < n; line++) {
		string s;
		cin >> s;

		for(int k = 0; k < s.length(); k++) {
			in[line][k] = s[k];
		}
	}
}

bool isMatch(const vector<vector<char>>& S, const vector<vector<char>>& T, int di, int dj) {
	int n = S.size();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (S[i][j] == '#') {
				int ti = i - di;
				int tj = j - dj;

				if (ti < 0 || ti >= n || tj < 0 || tj >= n || T[ti][tj] != '#') return false;
			}
		}
	}

	return true;
}

void task() {
	int n;
	cin >> n;

	vector<vector<char>> sMatrix(n, vector<char>(n));
	vector<vector<char>> tMatrix(n, vector<char>(n));
	readData(sMatrix, n);
	readData(tMatrix, n);

	for(int i = 0; i < 4; i++) {
		if (i > 0) rotate(sMatrix);

		pair<pair<int,int>,int> sInfo = getInfo(sMatrix);
		pair<pair<int,int>,int> tInfo = getInfo(tMatrix);

		if (sInfo.second != tInfo.second) break;
		if (sInfo.first.first == -1 || sInfo.first.second == -1 || tInfo.first.first == -1 || tInfo.first.second == -1) break;

		int di = sInfo.first.first - tInfo.first.first;
		int dj = sInfo.first.second - tInfo.first.second;

		if (isMatch(sMatrix, tMatrix, di, dj)) {
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