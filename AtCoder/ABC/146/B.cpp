#include <iostream>
#include <string>
using namespace std;

void task() {
	int n;
	string s;
	cin >> n >> s;

	for(char& c : s) {
		c = 'A' + (c - 'A' + n) % 26;
	}

	cout << s << endl;
}

int main() {
	task();
	return 0;
}