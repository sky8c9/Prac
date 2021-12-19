#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool gameStat(char a, char b) {
	bool aWin = (a == 'G' && b == 'C') || (a == 'C' && b == 'P') || (a == 'P' && b == 'G');
	return aWin;
}

bool comp(const pair<int,int> &a, const pair<int,int> &b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second > b.second;
}

void task() {
	int n,m;
	cin >> n >> m;

	vector<string> A(2*n);
	vector<pair<int, int>> score(2*n);
	for(int i = 0; i < 2*n; i++) {
		cin >> A[i];
		score[i] = make_pair(i, 0);
	}

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < 2*n; j+=2) {
			bool aWin = gameStat(A[score[j].first][i], A[score[j+1].first][i]);
			bool bWin = gameStat(A[score[j+1].first][i], A[score[j].first][i]);

			if (aWin) score[j].second++;
			if (bWin) score[j+1].second++;
		}

		sort(score.begin(), score.end(), comp);
	}

	for(int i = 0; i < score.size(); i++) {
		cout << score[i].first + 1 << endl;
	}

}

int main() {
	task();
	return 0;
}