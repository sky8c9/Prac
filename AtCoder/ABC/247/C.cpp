#include <iostream>
#include <string>

using namespace std;

void task() {
	int n;
	cin >> n;

	string s = "1";
	for(int i = 2; i <= n; i++) {
		s = s + " " + to_string(i) + " " + s;
	}

	cout << s << endl;
}

int main() {
	task();
	return 0;
}