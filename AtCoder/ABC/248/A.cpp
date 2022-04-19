#include <iostream>
#include <string>

using namespace std;

void task() {
	string s;
	cin >> s;

	int sum = 45;
	for(char c : s) {
		sum -= c - '0';
	}

	cout << sum << endl;
}

int main() {
	task();
	return 0;
}