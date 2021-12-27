#include <iostream>
#include <string>

using namespace std;
void task() {
	string s;
	cin >> s;

	int ans = 0;
	for(int i = 0; i < s.length() - 1; i++) {
		if (s[i] == '.') {
			if (s[i+1] - '0' >= 5)
				cout << ans + 1 << endl;
			else 
				cout << ans << endl;
			return;
		}

		ans = ans * 10 + s[i] - '0';
	}
}

int main() {
	task();
	return 0;
}