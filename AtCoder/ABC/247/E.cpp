#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll compute(const vector<int>& in, int x, int y) {
	ll ans = 0;
	int cntX = 0;
	int cntY = 0;

	for(int i = 0, j = 0; j < in.size(); j++) {
		if (in[j] == x) ++cntX;
		if (in[j] == y) ++cntY;

		while(cntX > 0 && cntY > 0) {
			ans += in.size() - j;
			if (in[i] == x) --cntX;
			if (in[i] == y) --cntY;
			++i;
		}
	}

	return ans;
}

void task() {
	int n, x, y;
	cin >> n >> x >> y;

	vector<int> a(n);
	for(int& val : a) cin >> val;

	vector<int> sub;
	ll ans = 0;
	for(int i = 0; i <= n; i++) {
		if (i == n || a[i] > x || a[i] < y) {
			ans += compute(sub, x, y);
			sub.clear();
		} else {
			sub.push_back(a[i]);
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}