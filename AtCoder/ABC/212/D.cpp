#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	int q;
	cin >> q;
	ll sum = 0;
	priority_queue<ll, vector<ll>, greater<ll>> pq;

	for(int i = 0; i < q; i++) {
		int p;
		cin >> p;

		if (p == 3) {
			ll min = pq.top();
			pq.pop();
			cout << sum + min << endl;
		} else {
			ll x;
			cin >> x;
			
			if (p == 1) {
				ll diff = x - sum;
				pq.push(diff);
			} else {
				sum += x;
			}
		}
	}
}

int main() {
	task();
	return 0;
}