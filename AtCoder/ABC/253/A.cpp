#include <iostream>

using namespace std;

void task() {
	int a,b,c;
	cin >> a >> b >> c;

	if ((b >= a && b <= c) || (b <= a && b >= c))cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	task();
	return 0;
}