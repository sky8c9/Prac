#include <iostream>

using namespace std;

void task() {
	int n;
	cin >> n;

	if (n < 40) cout << 40 - n << endl;
	else if (n < 70) cout << 70 - n << endl;
	else if (n < 90) cout << 90 - n << endl;
	else cout << "expert" << endl;
}

int main() {
	task();
	return 0;
}