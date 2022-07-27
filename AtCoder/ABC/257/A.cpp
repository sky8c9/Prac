#include <iostream>

using namespace std;

void task() {
	int n,x;
	cin >> n >> x;

	int idx = (x - 1) / n;
	cout << (char)('A' + idx) << endl;
}

int main() {
	task();
	return 0;
}