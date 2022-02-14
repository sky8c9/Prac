#include <iostream>

using namespace std;

void task() {
	int n,a,b;
	cin >> n >> a >> b;

	if (n * a > b) cout << b << endl;
	else cout << a * n << endl;
}

int main() {
	task();
	return 0;
}