#include <iostream>
#include <string>

using namespace std;
void task() {
	string s;
	cin >> s;

	int n = s.length();
	if (s[n-1] == 't') cout << "ist" << endl;
	else cout << "er" << endl;
}

int main() {
	task();
	return 0;
}