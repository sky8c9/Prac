#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n,x;
	cin >> n >> x;

	vector<int> v(n);
	for(int& val : v) cin >> val;

	int d = 0;
	int ans = 0;
	int index = 0;
	for(int i = 0; i <= n; i++) {
		if (d > x) break;
		d += v[index++];
		ans++;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}