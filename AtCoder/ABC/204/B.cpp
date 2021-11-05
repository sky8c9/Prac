#include <iostream>

using namespace std;

void task() {
	int ans = 0;
	int n;

	cin >> n;
	while(n--) {
		int val;
		cin >> val;

		if (val > 10) ans += val - 10;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}