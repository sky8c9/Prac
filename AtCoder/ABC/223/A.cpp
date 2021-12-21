#include <iostream>
using namespace std;

void task() {
	int n;
	cin >> n;
	if (n >= 100 && n % 100 == 0) {
		cout << "Yes" << endl;
	} else cout << "No" << endl;
}

int main() {
	task();
	return 0;
}