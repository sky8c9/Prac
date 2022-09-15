#include <iostream>
#include <string>

using namespace std;
void task() {
	string s,t;
	cin >> s >> t;

	if (s.length() > t.length()) cout << "No" << endl;
	else {
		bool ans = true;
		for(int i = 0; i < s.length(); i++) {
			if (s[i] != t[i]) {
				ans = false;
				break;
			}
		}
		if (ans) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

int main() {
	task();
	return 0;
}