#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;
void task() {
	int n; cin >> n;
	vector<pair<int, int>> stat;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		string s; 
		cin >> s;
		int sumDigit = 0;
		int sumX = 0;

		for(char c : s) {
			if (c == 'X') ++sumX;
			else {
				sumDigit += c - '0';
				ans += (c - '0') * sumX;
			}
		}

		stat.emplace_back(sumX, sumDigit);
	}

	sort(stat.begin(), stat.end(), [&](pair<int, int> p1, pair<int, int> p2) {
		return (ll) p1.first * p2.second > (ll) p1.second * p2.first;
	});

	ll cntX = stat[0].first;
	for(int i = 1; i < n; i++) {
		ans += cntX * stat[i].second;
		cntX += stat[i].first;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}