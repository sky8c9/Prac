#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

const ll MIN = -1e18;
template<class T> using max_heap = priority_queue<T>;
void task() {
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> p;
	p.emplace_back(1,0);
	for(int i = 0; i < n; i++) {
		int t, y;
		cin >> t >> y;
		p.emplace_back(t, y);
	}

	ll ans = MIN;
	ll taken = 0;
	max_heap<int> mxh;
	for(int i = n; i >= 0; i--) {
		auto[type, y] = p[i];
		if (type == 2) {
			if (y >= 0) {
				taken += y;
			} else {
				mxh.push(y);

				if (mxh.size() > k) {
					taken += mxh.top();
					mxh.pop();
				}
			} 
		} else {
			ans = max(ans, y + taken);
			if (k == 0) break;

			--k;
			if (mxh.size() > k) {
				taken += mxh.top();
				mxh.pop();
			}
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}