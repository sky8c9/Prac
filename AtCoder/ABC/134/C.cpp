#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> r(n);
	for(int& val : a) cin >> val;
	for(int i = n - 2; i >= 0; i--) {
		r[i] = max(a[i+1], r[i+1]);
	}

	int l = 0;
	for(int i = 0; i < n; i++) {
		cout << max(l, r[i]) << endl;
		l = max(a[i], l);
	}
}

int main() {
	task();
	return 0;
}