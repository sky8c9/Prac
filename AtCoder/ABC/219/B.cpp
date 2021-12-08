#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task() {
	vector<string> s(3);
	string t;
	cin >> s[0] >> s[1] >> s[2] >> t;

	string ans;
	for(int i = 0; i < t.length(); i++) {
		int index = t[i] - '1';
		ans += s[index];
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}