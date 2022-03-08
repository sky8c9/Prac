#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void task() {
	string s;
	cin >> s;

	sort(s.begin(), s.end());
	cout << s << endl;
}

int main() {
	task();
	return 0;
}