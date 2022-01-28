#include <iostream>
#include <string>

using namespace std;

void task() {
	string s;
	cin >> s;

	int r = s.length() - 1;
	while(s[r] == '0') r--;
	for(int l = 0; l < r; l++,r--) {
		if (s[l] != s[r]) {
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