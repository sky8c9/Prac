#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

void task() {
	ll n,q,x;
	cin >> n >> q >> x;

	vector<ll> w(2 * n);
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		ll val;
		cin >> val;

		sum += val;
		w[i] = w[i + n] = val;
	} 

	vector<int> nxt(n);
	vector<int> size(n, (x / sum) * n);
	ll s = 0;
	x %= sum;
	for(int i = 0, j = 0; i < n; i++) {
		while(s < x) {
			s+=w[j++];
		}

		size[i] += j - i;
		nxt[i] = j % n;
		s -= w[i];
	}

	int cur = 0;
	set<int> seen;
	vector<int> g;
	while(seen.count(cur) == 0) {
		seen.insert(cur);
		g.push_back(cur);
		cur = nxt[cur];
	}

	int tmp = nxt[cur];
	int clen = 1;
	while(tmp != cur) {
		tmp = nxt[tmp];
		clen++;
	}

	int l = g.size() - clen;
	for(int i = 0; i < q; i++) {
		ll k;
		cin >> k;
		k--;

		if (k < l) cout << size[g[k]] << endl;
		else {
			int r = (k - l) % clen;
			cout << size[g[l + r]] << endl;
		}
	}


}

int main() {
	task();
	return 0;
}