#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e6;
void task() {
	int n;
	cin >> n;

	int ans = 0;
	int mn = MAX;
	for(int i = 0; i < n; i++) {
		int val; 
		cin >> val;

		if (mn >= val) ans++;
		mn = min(mn, val);
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}