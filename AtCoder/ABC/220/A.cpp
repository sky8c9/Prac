#include <iostream>

using namespace std;

void task() {
	int a,b,c;
	cin >> a >> b >> c;
	int mul = 1;

	while(c <= b) {
		if (c >= a) {
			cout << c << endl;
			return;
		}

		mul++;
		c*=mul;
	}

	cout << -1 << endl;
}

int main() {
	task();
	return 0;
}