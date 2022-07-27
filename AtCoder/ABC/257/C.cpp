#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void task() {
	int n;
	string s;
	cin >> n >> s;

	int correct = 0;
	vector<pair<int,bool>> w;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;

		w.emplace_back(val, s[i] == '1' ? true : false);
		if (w[i].second) ++correct;
	}

	int ans = correct;
	sort(w.begin(), w.end());
	for(int i = 0; i < n; i++) {
		if (!w[i].second) ++correct;
		else --correct;

		if ((i < n - 1) && (w[i].first == w[i+1].first)) continue;
		ans = max(ans, correct);
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}