#include <iostream>

using namespace std;

void task() {
	int a,b,c;
	cin >> a >> b >> c;
	if ((a+b+c) >= 22) cout << "bust" << endl;
	else cout << "win" << endl;
}

int main() {
	task();
	return 0;
}