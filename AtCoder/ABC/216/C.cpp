#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void task() {
	long long n;
	cin >> n;

	string ans;
	while(n > 0) {
		if (n & 1) {
			n -= 1;
			ans += 'A';
		} else {
			n /= 2;
			ans += 'B';
		}
	}

	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}