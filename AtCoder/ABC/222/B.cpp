#include <iostream>

using namespace std;

void task() {
	int n,p;
	cin >> n >> p;

	int ans = 0;

	while(n--) {
		int val;
		cin >> val;

		if (val < p) ans++;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}