#include <iostream>
#include <string>

using namespace std;

void task() {
	string s;

	for(int i = 0; i < 26; i++) {
		int val;
		cin >> val;

		char c = 'a' + (val - 1);
		s += c;
	}

	cout << s << endl;	
}

int main() {
	task();
	return 0;
}