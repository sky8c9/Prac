#include <iostream>
#include <string>
using namespace std;

void task() {
	string s;
	cin >> s;

	cout << (s[0] - '0') * (s[2] - '0') << endl;
}

int main() {
	task();
	return 0;
}