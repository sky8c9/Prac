#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int n;
	cin >> n;
	vector<int> in(n);

	int sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> in[i];
		sum += in[i];
	}
	
	int curS = 0;
	int ans = 101;
	for(int i = 0; i < n - 1; i++) {
		curS += in[i];
		ans = min(ans, abs(curS - (sum - curS)));
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}