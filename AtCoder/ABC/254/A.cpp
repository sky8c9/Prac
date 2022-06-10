#include <iostream>
#include <string>

using namespace std;

void task() {
	int n;
	cin >> n;

	int ans = n % 100;
	if (ans < 10) {
		printf("0%d\n", ans);
	} else {
		cout << ans << endl;
	}
}

int main() {
	task();
	return 0;
}