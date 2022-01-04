#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
struct SegTree {
	vector<int> tree;
	int n;

	SegTree(vector<int>& in) {
		n = in.size();

		while (n != 0 && (n & (n-1)) != 0) {
			n++;
		}

		tree = vector<int>(2*n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = in[i];
		}

		for(int i = n - 1; i > 0; i--) {
			tree[i] = tree[2*i] + tree[2*i+1];
		}
	}

	void add(int index, int val) {
		tree[n + index] += val;
		for(int i = (n + index) / 2; i > 0; i /= 2) {
			tree[i] = tree[2*i] + tree[2*i+1];
		}
	}

	int query(int index, int curL, int curR, int qLeft, int qRight) {
		if (curR < qLeft || curL > qRight) return 0;
		if (curL >= qLeft && curR <= qRight) return tree[index];
		
		int mid = curL + (curR - curL) / 2;
		return query(2*index, curL, mid, qLeft, qRight) + query(2*index+1, mid + 1, curR, qLeft, qRight);
	}
};

int coord_compress(vector<int>& in) {
	map<int,int> m;
	for(int val : in) m[val] = 0;

	int counter = 0;
	for(auto&[k,v] : m) v = counter++;
	for(int&val : in) val = m[val]; 

	return m.size();
}

void task() {
	int n;
	cin >> n;

	vector<int> A(n);
	vector<int> B(n);
	map<int, vector<int>> AB;

	for(int&val : A) cin >> val;
	for(int&val : B) {
		int b;
		cin >> b;
		val = -b;
	}

	int msize = coord_compress(B);
	for(int i = 0; i < n; i++) {
		AB[A[i]].push_back(B[i]);
	}

	vector<int> dummy(msize);
	SegTree segT(dummy);
	long long ans = 0;
	for(auto[k,v] : AB) {
		for(int u : v) {
			segT.add(u, 1);
		}

		for(int u : v) {
			ans += segT.query(1, 0, segT.n - 1, 0, u);
		}
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}