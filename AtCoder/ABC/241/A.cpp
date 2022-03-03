#include <iostream>
#include <vector>

using namespace std;

void task() {
	vector<int> a(10);
	for(int& val : a) cin >> val;

	int ans = a[0];
	for(int i = 0; i < 2; i++) {
		ans = a[ans];
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}