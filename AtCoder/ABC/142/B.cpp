#include <iostream>

using namespace std;

void task() {
	int n, k;
	cin >> n >> k;

	int ans = 0;
	for(int i = 0; i < n; i++) {
		int h;
		cin >> h;

		if (h >= k) ans++;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}