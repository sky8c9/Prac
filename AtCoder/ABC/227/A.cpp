#include <iostream>

using namespace std;

void task() {
	int n,k,a;
	cin >> n >> k >> a;

	int ans = (k + a - 1) % n;
	if (ans == 0) cout << n << endl;
	else cout << ans << endl;
}

int main() {
	task();
	return 0;
}