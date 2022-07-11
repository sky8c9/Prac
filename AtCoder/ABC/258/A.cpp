#include <iostream>

using namespace std;

void task() {
	int k;
	cin >> k;

	int q = k / 60;
	int r = k % 60;

	if (r < 10) {
		printf("%d:0%d\n", 21 + q, r);
	} else {
		printf("%d:%d\n", 21 + q, r);
	}
}

int main() {
	task();
	return 0;
}