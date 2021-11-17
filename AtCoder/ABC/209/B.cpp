#include <iostream>

using namespace std;
void task() {
	int n, x;
	cin >> n >> x;

	int total = 0;
	for(int i = 1; i <= n; i++) {
		int val;
		cin >> val;

		if ((i & 1) == 0) val--;
		total += val;
	}

	if (x >= total) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	task();
	return 0;
}