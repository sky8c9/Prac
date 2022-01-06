#include <iostream>
#include <string>

using namespace std;

void task() {
	string s,t;
	cin >> s >> t;

	int diff = (t[0] - s[0] + 26) % 26;
	for(int i = 1; i < s.length(); i++) {
		char c = (s[i] - 'a' + diff) % 26 + 'a';
		if (c != t[i]) {
			cout << "No" << endl;
			return;
		}
	}

	cout << "Yes" <<endl;
}

int main() {
	task();
	return 0;
}