#include <iostream>

using namespace std;

void task() {
	int a,b,c;
	cin >> a >> b >> c;

	int ans = 21 - (a + b + c);
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}