#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	vector<int> b(n);
	vector<bool> dp(2);
	for(int&val : a) cin >> val;
	for(int&val : b) cin >> val;

	dp[0] = dp[1] = true;
	for(int i = 1; i < n; i++) {
		vector<bool> prev = dp;

		dp[0] = (prev[0] && abs(a[i] - a[i-1]) <= k) || (prev[1] && abs(a[i] - b[i-1]) <= k); 
		dp[1] = (prev[0] && abs(b[i] - a[i-1]) <= k) || (prev[1] && abs(b[i] - b[i-1]) <= k);
	}
	
	if (dp[0] || dp[1]) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	task();
	return 0;
}