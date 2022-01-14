#include <iostream>
#include <set>
#include <queue>

using namespace std;
using ll = long long;
const ll MAX = 1e18;

int main() {
	ll x;
	cin >> x;

	queue<ll> q;
	set<ll> arithL;
	for(ll i = 1; i <= 9; i++) {
		q.push(i);
		arithL.insert(i);

		for(ll j = 0; j <= 9; j++) {
			ll val = i * 10 + j;
			q.push(val);
			arithL.insert(val);
		}
	}

	while(!q.empty()) {
		ll cur = q.front(); q.pop();
		if (cur >= MAX) continue;

		int last2 = cur % 100;
		int lastD = cur % 10;
		int diff = (last2 % 10) - (last2 / 10);
		int next = lastD + diff;
		if (next >= 0 && next <= 9) {
			q.push(cur * 10 + next);
			arithL.insert(cur * 10 + next);
		}
	}

	auto itr = arithL.lower_bound(x);
	cout << *itr << endl;

}