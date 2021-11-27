#include <iostream>

using namespace std;

void task() {
	int s,t;
	cin >> s >> t;
	int ans = 0;

	for(int i = 0; i <= 100; i ++) {
		for(int j = 0; j <= 100 && i + j <= s; j++) {
			for(int k = 0; k <= 100 && i + j + k <= s && i * j * k <= t; k++) {
				ans++;
			}
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}