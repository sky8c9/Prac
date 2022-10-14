#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n;
	cin >> n;

	int ans = 0;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ans += a;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}