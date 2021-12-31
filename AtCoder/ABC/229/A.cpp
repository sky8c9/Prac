#include <iostream>
#include <string>

using namespace std;

void task() {
	string s1,s2;
	cin >> s1 >> s2;

	if ((s1 == "#." && s2 == ".#") || (s1 == ".#" && s2 == "#.")) {
		cout << "No" << endl;
	} else cout << "Yes" << endl;
}

int main() {
	task();
	return 0;
}