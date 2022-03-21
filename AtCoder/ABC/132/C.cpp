#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<int> d(n);
	for(int& val : d) cin >> val;
	sort(d.begin(), d.end());

	int mid = n / 2;
	int ans = d[mid] - d[mid - 1];

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}