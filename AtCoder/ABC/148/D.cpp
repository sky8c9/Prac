#include <iostream>

using namespace std;

void task() {
	int n;
	cin >> n;

	int cur = 1;
	int len = 0;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (a == cur) {
			cur++;
			len++;
		}
	}

	int ans = len == 0 ? -1 : n - len;
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}