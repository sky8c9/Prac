#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSum(vector<int>& a, int r) {
	int first = -1;
	int second = -1;
	for(int val : a) {
		if (val % 2 == r) {
			if (val > first) {
				second = first;
				first = val;
			} else if (val > second) second = val;
		}
	}

	return (first == -1 || second == -1) ? -1 : first + second;
}

void task() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int& val : a) cin >> val;
	
	int oddodd = maxSum(a, 1);
	int eveneven = maxSum(a, 0);
	int ans = max(oddodd, eveneven);
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}