#include <iostream>
#include <vector>
#include <string>

using namespace std;

void task() {
	int n,m;
	cin >> n >> m;

	vector<bool> status(n+1, false);
	int ac = 0;
	int wa = 0;
	vector<int> cnt(n+1);
	for(int i = 0; i < m; i++) {
		int p;
		string s;
		cin >> p >> s;

		if (status[p] == false) {
			if (s == "AC") {
				status[p] = true;
				ac++;
				wa += cnt[p];
			} else cnt[p]++;
		}
	}

	cout << ac << " " << wa << endl;
}

int main() {
	task();
	return 0;
}