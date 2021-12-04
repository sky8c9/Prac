#include <iostream>
#include <set>
#include <iterator>

using namespace std;

void task() {
	int l,q;
	cin >> l >> q;

	set<int> seen;
	seen.insert(0);
	seen.insert(l);

	while(q--) {
		int c,x;
		cin >> c >> x;

		if (c == 2) {	
			auto itr = seen.lower_bound(x);
			int hi = *itr;
			int lo = *prev(itr,1);
			cout << (hi - lo) << endl;
		} else seen.insert(x);
	}
}

int main() {
	task();
	return 0;
}