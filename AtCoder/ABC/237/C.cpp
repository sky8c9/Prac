#include <iostream>
#include <string>

using namespace std;

void task() {
	string s;
	cin >> s;

	int l = 0;
	int r = s.length() - 1;
	while(s[r] == 'a') {
		if (s[l] == 'a') l++;
		r--;
	}

	while(l < r) {
		if (s[l] != s[r]) {
			cout << "No" << endl;
			return;
		}
		l++;
		r--;
	}

	cout << "Yes" << endl;
}

int main() {
	task();
	return 0;
}