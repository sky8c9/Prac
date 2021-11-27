#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void task() {
	int n;
	cin >> n;
	vector<int> s(n);
	vector<int> t(n);
	vector<int> ans(n);

	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for(int i = 0; i < n; i++) {
		cin >> t[i];
		ans[i] = t[i];
	}

	for(int i = 0; i < 2; i++) {
		for(int j = 1; j <= n; j++) {
			ans[j % n] = min(ans[j % n], s[j - 1] + ans[j - 1]);
		}
	}

	for(int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}
}

int main() {
	task();
	return 0;
}