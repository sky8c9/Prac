#include <iostream>
#include <string>

using namespace std;

void task() {
	string s;
	cin >> s;

	int ans = 0;
	int l = 0;
	int r = s.length() - 1;
	while(l < r) {
		if (s[l] != s[r]) ans++;
		l++;
		r--;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}
