#include <iostream>
#include <algorithm>
using namespace std;

void task() {
	int x,y,n;
	cin >> x >> y >> n;

	int ans = min(n * x, (n / 3) * y + (n % 3) * x);
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}