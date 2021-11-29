#include <iostream>
#include <string>

using namespace std;

const string MATCH = "Hello,World!";
void task() {
	string s;
	cin >> s;

	if (s == MATCH) cout << "AC" << endl;
	else cout << "WA" << endl;
}

int main() {
	task();
	return 0;
}