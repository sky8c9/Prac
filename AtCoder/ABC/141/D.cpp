#include <iostream>
#include <queue>

using namespace std;

using ll = long long;

void task() {
	int n,m;
	cin >> n >> m;

	ll ans = 0;
	priority_queue<ll> pq;
	for(int i = 0; i < n; i++) {
		ll val;
		cin >> val;
		pq.push(val);
	}

	for(int i = 0; i < m; i++) {
		int cur = pq.top();
		pq.pop();
		pq.push(cur/2);
	}

	while(pq.size()) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}