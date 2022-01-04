#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int n,q;
	cin >> n >> q;

	vector<int> a(n);
	for(int&val : a) cin >> val;

	sort(a.begin(), a.end());
	while(q--) {
		int x;
		cin >> x;

		auto itr = lower_bound(a.begin(), a.end(), x);
		if (itr == a.end()) cout << 0 << endl;
		else cout <<  n - (itr - a.begin()) << endl;
	}
}

int main() {
	task();
	return 0;
}