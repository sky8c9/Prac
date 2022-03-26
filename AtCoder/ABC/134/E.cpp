#include <iostream>
#include <vector>
#include <queue>

using namespace std;
void task() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int& val : a) cin >> val;

	deque<int> ans;
	for(int i = 0; i < n; i++) {
		auto pos = lower_bound(ans.begin(), ans.end(), a[i]);

		if (pos == ans.begin()) ans.push_front(a[i]);
		else {
			--pos;
			*pos = a[i];
		}
	}

	cout << ans.size() << endl;
}

int main() {
	task();
	return 0;
}