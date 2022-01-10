#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(pair<string, pair<int,int>> a, pair<string, pair<int,int>> b) {
	if (a.first == b.first) return a.second.first > b.second.first;
	else return a.first < b.first;
}

void task() {
	int n;
	cin >> n;

	vector<pair<string, pair<int,int>>> resL(n);
	for(int i = 0; i < n; i++) {
		string s;
		int p;
		cin >> s >> p;
		resL[i] = make_pair(s, make_pair(p, i + 1));
	}

	sort(resL.begin(), resL.end(), cmp);
	for(auto&[name, info] : resL) {
		cout << info.second << endl;
	}
}

int main() {
	task();
	return 0;
}