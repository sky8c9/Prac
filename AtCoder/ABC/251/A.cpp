#include <iostream>
#include <string>

using namespace std;
void task() {
	string s;
	cin >> s;

	string ans;
	for(int i = 0; i < 6 / s.length(); i++) {
		ans += s;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}