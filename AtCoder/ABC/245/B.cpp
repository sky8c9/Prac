#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<bool> seen(2001);
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;

		seen[a] = true;
	}

	for(int i = 0; i <= 2000; i++) {
		if (!seen[i]) {
			cout << i << endl;
			return;
		}
	}
}

int main() {
	task();
	return 0;
}