#include <iostream>
#include <string>

using namespace std;

void task() {
	string s,t;
	cin >> s >> t;
	if (s < t) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	task();
	return 0;
}