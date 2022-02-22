#include <iostream>
#include <algorithm>

using namespace std;

void task() {
	int a,b;
	cin >> a >> b;

	int aPlusb = a + b;
	int aMulb = a * b;
	int aMinusb = a - b;

	cout << max(aPlusb, max(aMinusb, aMulb)) << endl;
}

int main() {
	task();
	return 0;
}