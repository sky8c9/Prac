#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
using ll = long long;

void task() {
	int n;
	cin >> n;

	deque<pair<ll, ll>> dq;
	for(int i = 0; i < n; i++) {
		int type;
		cin >> type;

		if (type == 1) {
			ll x, c;
			cin >> x >> c;

			if (!dq.empty() && dq.back().first == x) {
				dq.back().second += c;
			} else {
				dq.push_back({x, c});
			}
		} else if (type == 2) {
			ll c;
			cin >> c;

			ll sum = 0;
			while(c > 0) {
				ll m = min(c, dq.front().second);
				sum += m * dq.front().first;
				c -= m;

				dq.front().second -= m;
				if (dq.front().second == 0) dq.pop_front();
			}

			cout << sum << endl;
		}
	}
}

int main() {
	task();
	return 0;
}

