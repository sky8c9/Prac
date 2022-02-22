#include <iostream>

using namespace std;
void task() {
	int k,x;
	cin >> k >> x;

	for(int i = x - k + 1; i <= x + k - 1; i++) {
		cout << i << " ";
	}

	cout << endl;
}

int main() {
	task();
	return 0;
}