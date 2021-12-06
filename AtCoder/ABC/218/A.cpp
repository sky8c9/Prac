#include <iostream>
#include <string>

using namespace std;

void task() {
	int n;
	string s;

	cin >> n;
	cin >> s;

	if (s[n-1] == 'x') cout << "No" << endl;
	else cout << "Yes" << endl;
}

int main() {
	task();
	return 0;
}