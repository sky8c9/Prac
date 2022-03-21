#include <iostream>
#include <vector>
using namespace std;

void task() {
	int n;
	cin >> n;

	vector<int> p(n);
	for(int& val : p) cin >> val;

	int ans = 0;
	for(int i = 1; i < n - 1; i++) {
		bool c1 = p[i] > p[i - 1] && p[i] < p[i + 1];
		bool c2 = p[i] > p[i + 1] && p[i] < p[i - 1];
		if (c1 || c2) ans++;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}