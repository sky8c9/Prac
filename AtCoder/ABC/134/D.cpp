#include <iostream>
#include <vector>

using namespace std;

void task() {
	int n;
	cin >> n;

	vector<int> ans;
	vector<int> a(n);
	vector<bool> sum(n);

	for(int& val : a) cin >> val;

	for(int i = n; i > 0; i--) {
		bool tmp = a[i - 1];

		for(int j = i + i ; j <= n; j+=i) {
			tmp ^= sum[j - 1];
		}

		sum[i - 1] = tmp;
	}
	
	for(int i = 0; i < n; i++) {
		if (sum[i]) {
			ans.push_back(i+1);
		}
	}

	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) {
		if (i) cout << " " << ans[i];
		else cout << ans[i];
	}

	cout << endl;
}

int main() {
	task();
	return 0;
}