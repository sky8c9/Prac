#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void task() {
	int n;
	cin >> n;

	unordered_map<int, set<vector<int>>> hmap;
	int ans = n;

	while(n--) {
		int l;
		cin >> l;

		vector<int> a(l);
		for(int i = 0; i < l; i++) {
			cin >> a[i];
		}

		if (hmap[l].count(a) == 0) {
			hmap[l].insert(a);
		} else {
			ans--;
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}