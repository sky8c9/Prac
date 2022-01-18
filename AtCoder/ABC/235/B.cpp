#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<int> v(n);
	for(int&val : v) cin >> val;

	int i = 0;
	for(i = 0; i < n - 1; i++) {
		if (v[i] >= v[i+1]) {
			cout << v[i] << endl;
			return;
		}
	}

	if (i == n-1) cout << v[n-1] << endl;
}

int main() {
	task();
	return 0;
}