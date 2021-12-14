#include <iostream>

using namespace std;

void task() {
	int a,b;
	cin >> a >> b;

	int diff = a - b;
	int ans = 1;

	while(diff--) {
		ans *= 32;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}