#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct Ratio {
	ll x;
	ll y;

	Ratio() {
		x = 0;
		y = 0;
	}

	Ratio(ll ix, ll iy) {
		x = ix;
		y = iy;
	}

	bool operator<(const Ratio& o) const {
		return y * o.x < o.y * x;
	}

	bool operator<=(const Ratio& o) const {
		return y * o.x <= o.y * x;
	}
};

void task() {
	int n;
	cin >> n;
	vector<pair<Ratio, Ratio>> pts;

	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		pts.push_back(make_pair(Ratio(x-1, y), Ratio(x, y-1)));
	}

	sort(pts.begin(), pts.end());
	Ratio cur;
	int ans = 0;

	for(auto p : pts) {
		if (cur <= p.second) {
			ans++;
			cur = p.first;
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}