#include <iostream>
#include <string>

using namespace std;
void task() {
	string s;
	cin >> s;

	for(int i = 0; i < s.length() - 4; i++) {
		s = '0' + s;
	}

	cout << s << endl;
}

int main() {
	task();
	return 0;
}