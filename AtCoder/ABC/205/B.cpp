#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n;
	cin >> n;
	vector<bool> seen(n+1);

	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;

		seen[val] = 1;
	}

	for(int i = 1; i <= n; i++) {
		if (seen[i] == 0) {
			cout << "No" << endl;
			return;
		}
	}

	cout << "Yes" << endl;
}

int main() {
	task();
	return 0;
}