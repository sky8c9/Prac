#include <iostream>
#include <string>

using namespace std;
void task() {
	string s;
	cin >> s;

	if (s[0] == s[1] && s[1] == s[2]) cout << "-1" << endl;
	else if (s[0] == s[1]) cout << s[2] << endl;
	else if (s[0] == s[2]) cout << s[1] << endl;
	else cout << s[0] << endl;
}

int main() {
	task();
	return 0;
}