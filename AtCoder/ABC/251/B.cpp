#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void task() {
	int n,w;
	cin >> n >> w;

	vector<int> a(n);
	unordered_set<int> ans;
	for(int&val : a) cin >> val;
	for(int i = 0; i < n; i++) {
		if (a[i] <= w) ans.insert(a[i]);

		for(int j = i + 1; j < n; j++) {
			if (a[j] <= w) ans.insert(a[j]);
			if (a[i] + a[j] <= w) ans.insert(a[i] + a[j]);

			for(int k = j + 1; k < n; k++) {
				if (a[k] <= w) ans.insert(a[k]);
				if (a[i] + a[k] <= w) ans.insert(a[i] + a[k]);
				if (a[j] + a[k] <= w) ans.insert(a[j] + a[k]);
				if (a[i] + a[j] + a[k] <= w) ans.insert(a[i] + a[j] + a[k]);
			}
		}
	}

	cout << ans.size() << endl;
}

int main() {
	task();
	return 0;
}