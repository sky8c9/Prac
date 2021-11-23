#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int const MAX = 1e9;

void task() {
	int n,m;
	cin >> n >> m;

	vector<int> a(n);
	vector<int> b(m);
	for(int& val : a) cin >> val;
	for(int& val : b) cin >> val;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int ans = MAX;
	
	for(int i = 0, j = 0; i < n && j < m;) {
		if (a[i] == b[j]) {
			cout << 0 << endl;
			return;
		} else if (a[i] > b[j]) {
			ans = min(ans, a[i] - b[j]);
			j++;
		} else {
			ans = min(ans, b[j] - a[i]);
			i++;
		}
	}
	
	cout << ans << endl;
}

int main() {
	task();
	return 0;
}