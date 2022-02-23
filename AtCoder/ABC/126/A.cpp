#include <iostream>
#include <string>
using namespace std;

void task() {
	int n,k;
	cin >> n >> k;

	string s;
	cin >> s;

	char c = s[k - 1];
	if (c == 'A') s[k-1] = 'a';
	else if (c == 'B') s[k-1] = 'b';
	else if (c == 'C') s[k-1] = 'c';

	cout << s << endl;
}

int main() {
	task();
	return 0;
}