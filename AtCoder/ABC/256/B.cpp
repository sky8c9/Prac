#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<int> sq(4, 0);
	int p = 0;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;

		sq[0] = 1;
		vector<int> tmp(4);
		for(int j = 0; j < sq.size(); j++) {
			if (sq[j] == 0) continue;
			if (j + a >= 4) p += sq[j];
			else tmp[j + a] += sq[j];
		}

		sq = tmp;
	}

	cout << p << endl;
}

int main() {
	task();
	return 0;
}