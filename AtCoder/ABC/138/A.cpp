#include <iostream>
#include <string>

using namespace std;

void task() {
	int a;
	string s;

	cin >> a >> s;
	if (a < 3200) cout << "red" << endl;
	else cout << s << endl;
}

int main() {
	task();
	return 0;
}