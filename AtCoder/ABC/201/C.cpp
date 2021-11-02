#include <iostream>
#include <string>
using namespace std;

void task() {
	int ans = 0;
	string s;

	cin >> s;
	for(int i = 0; i < 10000; i++) {
		bool flag[10]{false};
		bool test = true;
		int num = i;

		for(int j = 0; j < 4; j++) {
			flag[num % 10] = true;
			num /= 10;
		}

		for(int k = 0; k < 10; k++) {
			if (s[k] == 'o' && !flag[k]) test = false;
			if (s[k] == 'x' && flag[k]) test = false;
		}

		ans += test;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}