#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void task() {
	int q;
	cin >> q;
	
	map<int, int> freq;
	for(int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int x;
			cin >> x;

			freq[x]++;
		} else if (type == 2) {
			int x, c;
			cin >> x >> c;

			freq[x]-=min(c, freq[x]);
			if (freq[x] == 0) freq.erase(x);
		} else {
			int mn = freq.begin()->first;
			int mx = freq.rbegin()->first;

			cout << (mx - mn) << endl;
		}
	}
}

int main() {
	task();
	return 0;
}