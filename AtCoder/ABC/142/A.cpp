#include <iostream>

using namespace std;

void task() {
	int n;
	cin >> n;

	int count = n % 2 ? n / 2 + 1 : n / 2;
	printf("%.6f \n", count * 1.0 / n);
}

int main() {
	task();
	return 0;
}