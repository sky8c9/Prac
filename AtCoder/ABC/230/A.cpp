#include <iostream>
#include <string>

using namespace std;

void task() {
	int n;
	cin >> n;

	cout << "AGC";
	if (n < 100) cout << "0";
	if (n < 10) cout << "0";
	if (n < 42) cout << n << endl;
	else cout << n+1 << endl;
}

int main() {
	task();
	return 0;
}