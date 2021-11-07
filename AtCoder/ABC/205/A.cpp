#include <iostream>

using namespace std;

void task() {
	int a,b;
	cin >> a >> b;

	double ans = a * (b / 100.0);
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}