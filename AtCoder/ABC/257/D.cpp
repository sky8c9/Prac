#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

struct Point {
	int x,y,p,i;

	Point() {
		x = y = p = i = -1;
	}

	Point(int xx, int yy, int pp, int ii) {
		x = xx;
		y = yy;
		p = pp;
		i = ii;
	}
};

bool doable(vector<Point>& points, ll s) {
	for(int i = 0; i < points.size(); i++) {
		queue<Point> q;
		vector<bool> seen(points.size());
		q.push(points[i]);
		seen[i] = true;
		int cnt = 1;
		while(!q.empty()) {
			if (cnt == points.size()) return true;

			Point cur = q.front(); q.pop();
			for(int j = 0; j < points.size(); j++) {
				ll d = (ll) abs(cur.x - points[j].x) + abs(cur.y - points[j].y);
				if (j == cur.i || seen[j] || cur.p * s < d) continue;
				seen[j] = true;
				cnt++;
				q.push(points[j]);
			}
		}

	}

	return false;
}

void task() {
	int n;
	cin >> n;

	vector<Point> points(n);
	for(int i = 0; i < n; i++) {
		int x,y,p;
		cin >> x >> y >> p;
		points[i] = Point(x,y,p,i);
	}

	ll lo = 0;
	ll hi = 4*1e9;
	while(lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (doable(points, mid)) hi = mid;
		else lo = mid + 1;
	}

	cout << lo << endl;
}

int main() {
	task();
	return 0;
}