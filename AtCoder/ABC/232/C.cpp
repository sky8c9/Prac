#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

void task() {
	int n,m;
	cin >> n >> m;

	vector<pair<int,int>> edgeAB;
	unordered_map<int, unordered_set<int>> adjLCD(n);
	for(int i = 0; i < m; i++) {
		int a,b;
		cin >> a >> b;
		a--;b--;
		edgeAB.emplace_back(a,b);
	}

	for(int i = 0; i < m; i++) {
		int c,d;
		cin >> c >> d;
		c--;d--;
		adjLCD[c].insert(d);
		adjLCD[d].insert(c);
	}

	vector<int> p(n);
	for(int i = 0; i < n; i++) p[i] = i;
	do {
		bool check = true;

		for(const auto&[a,b] : edgeAB) {
			if (adjLCD[p[a]].count(p[b]) == 0) {
				check = false;
				break;
			} 
		}

		if (check) {
			cout << "Yes" << endl;
			return;
		}
    } while(next_permutation(p.begin(), p.end()));

    cout << "No" << endl;
}

int main() {
	task();
	return 0;
}