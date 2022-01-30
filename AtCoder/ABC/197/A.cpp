#include <iostream>
#include <string>
using namespace std;

void task() {
	string s;
	cin >> s;

	cout << s.substr(1) + s[0] << endl;
}

int main() {
	task();
	return 0;
}