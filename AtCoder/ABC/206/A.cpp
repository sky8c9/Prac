#include <iostream>

using namespace std;

const int p = 206;

void task() {
	int n;
	cin >> n;

	int ans = 1.08 * n;
	if (ans < p) cout << "Yay!" << endl;
	else if (ans == p) cout << "so-so" << endl;
	else cout << ":(" << endl;
}

int main() {
	task();
	return 0;
}