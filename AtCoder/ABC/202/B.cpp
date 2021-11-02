#include <iostream>
#include <string>
using namespace std;

void task() {
	string s;
	cin >> s;
	int n = s.length();

	for(int i = 0; i < n; i++) {
		char c = s[n-1-i];
		if (c == '6') cout << '9';
		else if (c == '9') cout << '6';
		else cout << c;
	}

	cout << endl;
}

int main() {
	task();
	return 0;
}