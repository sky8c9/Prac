#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
const int SIZE = 1048576;

void task() {
	int q;
	cin >> q;

	vector<ll> vals(SIZE, -1);
	set<int> empty;
	for(int i = 0; i < SIZE; i++) empty.insert(i);

	while(q--) {
		int t;
		ll x;
		cin >> t >> x;

		if (t == 1) {
			int val = x % SIZE;

			if (vals[val] != -1) {
				auto itr = empty.lower_bound(val);
				if (itr == empty.end()) val = *empty.begin();
				else val = *itr;
			} 

			vals[val] = x;
			empty.erase(val);
		} else {
			cout << vals[x % SIZE] << endl;
		}
	}
}

int main() {
	task();
	return 0;
}