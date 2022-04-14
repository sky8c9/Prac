#include <iostream>
#include <string>

using namespace std;

void task() {
	string s;
	cin >> s;

	for(int i = s.length(); i > 0; i--) {
		s[i] = s[i-1];
	}

	s[0] = '0';
	cout << s << endl;
}

int main() {
	task();
	return 0;
}