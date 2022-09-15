#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

string ans = "-1";
unordered_set<string> seen;

bool find(string cur, int index, vector<string>& s, int r) {
	if (r < 0) return false;
	if (index == s.size() - 1) {
		cur += s[index];
		if (cur.length() >= 3 && seen.count(cur) == 0) {
			ans = cur;
			return true;
		} else return false;
	}

	string added = s[index] + "_";
	for(int i = 0; i <= r; i++) {
		if (find(cur + added, index + 1, s, r - i)) return true;
		added += "_";
	}

	return false;
}

void task() {
	int n,m;
	cin >> n >> m;

	vector<string> s(n);
	int r = 16 - (n - 1);
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		r -= s[i].length();
	}

	for(int i = 0; i < m; i++) {
		string t;
		cin >> t;
		seen.insert(t);
	}

	sort(s.begin(), s.end());
	do {
		if (find("", 0, s, r)) break;
	} while (next_permutation(s.begin(), s.end()));

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}

