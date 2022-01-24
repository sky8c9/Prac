#include <iostream>

using namespace std;
using ll = long long;

ll genNum(int num, int freq) {
	ll ans = num;

	for(int i = 1; i < freq; i++) {
		ans *= 10;
		ans += num;
	}

	return ans;
}

void task() {
	int a,b;
	cin >> a >> b;

	if (a < b) {
		cout << genNum(a,b) << endl;
	} else cout << genNum(b,a) << endl;
}

int main() {
	task();
	return 0;
}