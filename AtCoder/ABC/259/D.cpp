#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;

struct Circle {
	ll x,y,r;

	Circle(ll xx, ll yy, ll rr) {
		x = xx;
		y = yy;
		r = rr;
	}
};

ll distance(ll x1, ll y1, ll x2, ll y2) {
	ll dx = abs(x1 - x2);
	ll dy = abs(y1 - y2);
	return dx * dx + dy * dy;
}

void task() {
	int n;
	cin >> n;

	ll sx,sy,tx,ty;
	cin >> sx >> sy >> tx >> ty;

	set<int> tSet; 
	queue<int> q;
	vector<bool> seen(n);
	vector<Circle> cir;
	for(int i = 0; i < n; i++) {
		ll x,y,r;
		cin >> x >> y >> r;
		cir.emplace_back(x,y,r);

		if (distance(sx,sy,x,y) == r * r) {
			q.push(i);
			seen[i] = true;
		}

		if (distance(tx,ty,x,y) == r * r) {
			tSet.insert(i);
		}
	}

	vector<vector<int>> adj(n);
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			ll d = distance(cir[i].x, cir[i].y, cir[j].x, cir[j].y);
			ll r2 = (cir[i].r + cir[j].r) * (cir[i].r + cir[j].r);
			if (d != 0 && d <= r2) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	while(!q.empty()) {
		int cur = q.front(); q.pop();
		if (tSet.count(cur)) {
			cout << "Yes" << endl;
			return;
		}

		for(int nxt : adj[cur]) {
			if (seen[nxt]) continue;
			seen[nxt] = true;
			q.push(nxt);
		}
	}

	cout << "No" << endl;
}

int main() {
	task();
	return 0;
}