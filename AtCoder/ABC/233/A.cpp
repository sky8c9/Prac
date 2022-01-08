#include <iostream>
#include <algorithm>

using namespace std;

void task() {
	int x,y;
	cin >> x >> y;

	int ans = max(0, (y - x + 9) / 10);
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}