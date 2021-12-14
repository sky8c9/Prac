#include <iostream>
#include <string>

using namespace std;

void task() {
	string s,t;
	cin >> s >> t;

	bool flag = false;
	if (s == t) flag = true;

	for(int i = 1; i < s.length(); i++) {
		if (s[i] != t[i]) {
			swap(s[i], s[i-1]);

			if (s == t) {
				flag = true;
				swap(s[i], s[i-1]);
				break;
			}

			swap(s[i], s[i-1]);
		}
	}

	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	task();
	return 0;
}