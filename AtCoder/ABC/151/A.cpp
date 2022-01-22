#include <iostream>

using namespace std;

void task() {
	char c;
	cin >> c;
	cout << char('a' + (c - 'a' + 1)) << endl;
}

int main() {
	task();
	return 0;
}