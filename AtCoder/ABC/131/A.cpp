#include <iostream>
#include <string>

using namespace std;

void task() {
	string s;
	cin >> s;

	bool bad = (s[0] == s[1]) || (s[1] == s[2]) || (s[2] == s[3]);
	if (bad) cout << "Bad" << endl;
	else cout << "Good" << endl;
}

int main() {
	task();
	return 0;
}