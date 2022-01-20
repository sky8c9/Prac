#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e9;

void task() {
	int n, l;
	cin >> n >> l;

	int sum = l * n + n * (n + 1) / 2 - n;
	int ans = MAX;
	for(int i = 0; i < n; i++) {
		int cand = sum - (l + i);
		if (abs(cand - sum) < abs(ans - sum)) ans = cand;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}