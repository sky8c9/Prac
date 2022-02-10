#include <iostream>
#include <string>

using namespace std;

void task() {
	int n;
	string s;
	cin >> n >> s;

	if (n & 1) {
		cout << "No" << endl;
		return;
	}

	for(int i = 0; i < n / 2; i++) {
		if (s[i] != s[i + n / 2]) {
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