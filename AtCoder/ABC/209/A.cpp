#include <iostream>

using namespace std;

void task() {
	int a, b;
	cin >> a >> b;

	if (a > b) cout << 0 << endl;
	else cout << b - a + 1 << endl;
}

int main() {
	task();
	return 0;
}