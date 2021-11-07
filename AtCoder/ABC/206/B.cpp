#include <iostream>
#include <cmath>

using namespace std;

void task() {
	int n;
	cin >> n;

	for(int i = 1; i <= sqrt(2*n) + 1; i++) {
		if (i * (i + 1) / 2 >= n) {
			cout << i << endl;
			return;
		}
	}
}

int main() {
	task();
	return 0;
}