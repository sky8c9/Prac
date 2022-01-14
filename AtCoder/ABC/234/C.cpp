#include <iostream>
#include <string>
#include <queue>

using namespace std;

void task() {
	long long k;
	cin >> k;

	string ans;
	while(k > 0) {
		if (k % 2 == 0) ans = '0' + ans;
		else ans = '2' + ans;
		k /= 2;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}