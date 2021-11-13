#include <iostream>

using namespace std;

void task() {
	int a, b;
	cin >> a >> b;

	if (b >= a && b <= 6*a) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

int main() {
	task();
	return 0;
}