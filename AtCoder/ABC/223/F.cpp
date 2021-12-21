#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int MAX = 1e5 + 1;

struct SegTree {
	vector<pair<int, int>> tree;
	int n;

	SegTree(vector<pair<int, int>> in) {
		n = in.size();

		while(n != 0 && (n & n-1) != 0) {
			n++;
		}

		tree = vector<pair<int, int>>(2 * n);
		for(int i = 0; i < in.size(); i++) {
			tree[i + n] = in[i]; 
		}

		for(int i = n - 1; i > 0; i--) {
			tree[i] = merge(tree[2*i], tree[2*i+1]);
		}
	}

	pair<int,int> merge(pair<int,int>& fromL, pair<int,int>& fromR) {
		auto[lmin, lsum] = fromL;
		auto[rmin, rsum] = fromR;
		return make_pair(min(lmin, lsum + rmin), lsum + rsum);
	}

	pair<int,int> query(int cur, int left, int right, int qleft, int qright) {
		if (left >= qleft && right <= qright) {
			return tree[cur];
		}

		if (right < qleft || left > qright) {
			return make_pair(MAX, 0);
		}

		int mid = left + (right - left) / 2;
		auto ansL = query(2*cur, left, mid, qleft, qright);
		auto ansR = query(2*cur+1, mid + 1, right, qleft, qright);
		return merge(ansL, ansR);
	}

	void update(int index, pair<int,int> val) {
		tree[index + n] = val; 
		for(int i = (n + index) / 2; i > 0; i /= 2) {
			tree[i] = merge(tree[2*i], tree[2*i+1]);
		}
	}
};

void task() {
	int n,q;
	string s;
	cin >> n >> q >> s;

	vector<pair<int, int>> p(n);
	int total = 0;
	for(int i = 0; i < n; i++) {
		if (s[i] == '(') p[i] = make_pair(0, 1);
		else p[i] = make_pair(-1,-1);
	}

	SegTree segT(p);
	while(q--) {
		int type,l,r;
		cin >> type >> l >> r;
		l--;r--;

		if (type == 1) {
			swap(p[l], p[r]);
			segT.update(l, p[l]);
			segT.update(r, p[r]);
		} else {
			auto[min, sum] = segT.query(1, 0, segT.n - 1, l, r);
			if (min == 0 && sum == 0) {
				cout << "Yes" << endl;
			} else cout << "No" << endl;
		}
	}
}

int main() {
	task();
	return 0;
}