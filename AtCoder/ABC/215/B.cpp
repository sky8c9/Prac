#include <iostream>

using namespace std;

void task() {
	long long n;
	cin >> n;

	long long start = 1;
	int k = 0;

	while (start <= n) {
		start <<= 1;
		k++;
	}

	cout << k - 1 << endl;
}

int main() {
	task();
	return 0;
}