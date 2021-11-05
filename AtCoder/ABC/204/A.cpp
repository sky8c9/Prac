#include <iostream>

using namespace std;

void task() {
	int x,y;
	cin >> x >> y;

	if (x == y) cout << x << endl;
	else if (x + y == 1) cout << 2 << endl;
	else if (x + y == 2) cout << 1 << endl;
	else cout << 0 << endl;
}

int main() {
	task();
	return 0;
}