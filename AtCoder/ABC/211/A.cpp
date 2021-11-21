#include <iostream>

using namespace std;

void task() {
	int a,b;
	cin >> a >> b;

	double ans = (a - b) / 3.0 + b;
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}