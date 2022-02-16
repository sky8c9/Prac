#include <iostream>

using namespace std;
void task() {
	int a,b;
	cin >> a >> b;

	if (a < 0 || a > 9 || b < 0 || b > 9) cout << -1 << endl;
	else cout << a*b << endl;
}

int main() {
	task();
	return 0;
}