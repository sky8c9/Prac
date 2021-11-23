#include <iostream>

using namespace std;

void task() {
	int a,b;
	cin >> a >> b;

	if (a - b == a) cout << "Gold" << endl;
	else if (b - a == b) cout << "Silver" << endl;
	else cout << "Alloy" << endl;
}

int main() {
	task();
	return 0;
}