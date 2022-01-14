#include <iostream>

using namespace std;

int computeFt(int t) {
	return t*t + 2*t + 3;
}

void task() {
	int t;
	cin >> t;

	int ans = computeFt(computeFt(computeFt(t) + t) + computeFt(computeFt(t)));
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}