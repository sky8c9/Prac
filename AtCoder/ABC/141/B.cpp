#include <iostream>
#include <string>

using namespace std;

void task() {
	string s;
	cin >> s;

	for(int i = 0; i < s.length(); i++) {
		if ((i % 2 == 0 && s[i] == 'L') || (i % 2 != 0 && s[i] == 'R')) {
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