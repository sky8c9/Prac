#include <iostream>
#include <string>

using namespace std;

void task() {
	int n;
	string s;

	cin >> n >> s;
	for(int i = 0; i < n; i++) {
		if (s[i] == '1') {
			if (i & 1) cout << "Aoki" << endl;
			else cout << "Takahashi" << endl;
			return;
		}
	}
}

int main() {
	task();
	return 0;
}