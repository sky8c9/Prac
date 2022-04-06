#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

void task() {
	int n,k,x;
	cin >> n >> k >> x;

	priority_queue<int, vector<int>> pq;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;

		pq.push(val);
	}

	while (k > 0 && !pq.empty()) {
		int cur = pq.top(); pq.pop();

		if (cur <= x) {
			k--;
		} else {
			int q = min(k, cur / x);
			pq.push(cur - q * x);
			k -= q;
		}
	}

	ll ans = 0;
	while(!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}