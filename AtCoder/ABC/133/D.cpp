#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> ans(n);
	int val = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if (i & 1) {
			val -= a[i];
		} else {
			val += a[i];
		}
	}

	ans[0] = val / 2;
	for(int i = 1; i < n; i++) {
		ans[i] = a[i-1] - ans[i-1];
	}

	for(int i = 0; i < n; i++) {
		cout << 2 * ans[i] << " ";
	}

	cout << endl;
}

int main() {
	task();
	return 0;
}