#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task() {
	string s;
	cin >> s;

	bool c1 = false;
	bool c2 = false;
	vector<bool> seen1(26);
	vector<bool> seen2(26);
	for(char c : s) {
		if (c >= 'a' && c <= 'z') {
			if (seen1[c - 'a']) {
				cout << "No" << endl;
				return;
			}

			c1 = true;
			seen1[c - 'a'] = true;
		}

		if (c >= 'A' && c <= 'Z') {
			if (seen2[c - 'A']) {
				cout << "No" << endl;
				return;
			}

			c2 = true;
			seen2[c - 'A'] = true;
		}
	}

	bool ans = c1 & c2;
	if (ans)  cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	task();
	return 0;
}