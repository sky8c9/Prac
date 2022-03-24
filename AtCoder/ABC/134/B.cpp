#include <iostream>

using namespace std;

void task() {
	int n,d;
	cin >> n >> d;

	int x = 2 * d + 1;
	cout << (n + x - 1) / x << endl;
}

int main() {
	task();
	return 0;
}