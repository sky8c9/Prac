#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
const int MOD = 998244353;

struct SegTree {
	vector<long long> tree;
	int n;

	SegTree(int size) {
		n = size;

		// make n power of 2
		while(n != 0 && (n & (n-1)) != 0) {
			n++;
		}

		tree = vector<long long>(2*n);
	}

	long long query(int cur, int curLeft, int curRight, int queryLeft, int queryRight) {
		bool inRange = queryLeft <= curLeft && curRight <= queryRight;
		bool outRange = curRight < queryLeft || curLeft > queryRight;

		if (inRange) {
			return tree[cur];
		} 

		if (outRange) {
			return 0;
		}

		int mid = curLeft + (curRight - curLeft) / 2;
		return (query(2*cur, curLeft, mid, queryLeft, queryRight)
				+ query(2*cur+1, mid + 1, curRight, queryLeft, queryRight)) % MOD;

	}

	void add(int index, long long val) {
		tree[index + n] = (tree[index + n] + val) % MOD;
		for(int i = (index + n) / 2; i >= 1; i /= 2) {
			tree[i] = (tree[2*i] + tree[2*i+1]) % MOD;
		}
	}
};

long long pow_mod(long long base, long long pow) {
	long long ans = 1;

	while(pow > 0) {
		if (pow & 1) {
			ans *= base;
			ans %= MOD;
		}

		base *= base;
		base %= MOD;
		pow >>= 1;
	}

	return ans;
}

int coord_compression(vector<int>& in) {
	map<int,int> compressMap;
	for(int i = 0; i < in.size(); i++) {
		compressMap[in[i]] = 0;
	}

	int index = 0;
	for(auto&[k,v] : compressMap) {
		v = index++;
	}

	for(int& key : in) {
		key = compressMap[key];
	}

	return compressMap.size();
}

void task() {
	int n;
	cin >> n;

	long long ans = 0;
	vector<int> a(n);
	for(int& val : a) cin >> val;

	long long mod_inverse_1half = pow_mod(2, MOD - 2);
	int size = coord_compression(a);
	SegTree segT(size);

	for(int i = 0; i < n; i++) {
		ans = (ans + segT.query(1, 0, segT.n - 1, 0, a[i]) * pow_mod(2, i - 1)) % MOD;
		segT.add(a[i], pow_mod(mod_inverse_1half, i));
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}

