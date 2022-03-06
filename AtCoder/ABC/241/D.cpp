#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	int q;
	cin >> q;

	multiset<ll> nums;
	for(int i = 0; i < q; i++) {
		int type;
		ll x;
		cin >> type >> x;

		if (type == 1) {
			nums.insert(x);
		} else {
			int k;
			cin >> k;

			multiset<ll>::iterator itr;
			if (type == 2) {
				itr = nums.upper_bound(x);
				while(k > 0 && itr != nums.begin()) {
					--itr;
					--k;
				}
			} else {
				itr = nums.lower_bound(x);
				if (itr != nums.end()) {
					while(k > 1 && itr != prev(nums.end())) {
						++itr;
						--k;
					}
					--k;
				}
			}

			if (k == 0) {
				cout << *itr << endl;
			} else {
				cout << -1 << endl;
			}
		}
	}
	
}

int main() {
	task();
	return 0;
}