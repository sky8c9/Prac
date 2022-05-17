#include <iostream>

using namespace std;

void task() {
	int w;
	cin >> w;

	cout << 300 << endl;
	for(int i = 1; i <= 100; i++) {
		cout << i << " " << (i * 100) << " " << (i * 10000) << " ";
	}
}

int main() {
	task();
	return 0;
}