#include <iostream>
#include <cmath>

using namespace std;
void task() {
	int n;
	cin >> n;

	for(int i = 1; i * i <= n; i++) {
		if (n % i != 0) continue;
		if (i > 0 && i <= 9 && (n/i) > 0 && (n/i) <= 9) {
			cout << "Yes" << endl;
			return;
		}
	}

	cout << "No" << endl;
}

int main() {
	task();
	return 0;
}