#include <iostream>

using namespace std;

void task() {
	int n;
	cin >> n;

	int ans = 0;
	while(n--) {
		int s;
		cin >> s;
		bool find = false;

		for(int a = 1; a <= 150; a++) {
			for(int b = 1; b <= 150; b++) {
				if (3*a + 3*b + 4*a*b == s) {
					find = true;
				}
			}
		}

		if (!find) ans++;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}