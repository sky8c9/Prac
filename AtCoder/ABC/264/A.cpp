#include <iostream>
#include <string>
using namespace std;

void task() {
	int l,r;
	cin >> l >> r;

	string s = "atcoder";
	for(int i = l; i <= r; i++) {
		cout << s[i-1];
	}

	cout << endl;
}

int main() {
	task();
	return 0;
}

