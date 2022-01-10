#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
void task() {
	int n,q;
	cin >> n >> q;

	vector<pair<int, pair<int,int>>> XST(n);
	set<pair<int, int>> D;

	for(int i = 0; i < n; i++) {
		int s,t,x;
		cin >> s >> t >> x;
		XST[i] = {x, {s-x, t-x}};
	}

	sort(XST.begin(), XST.end());
	for(int i = 0; i < q; i++) {
		int d;
		cin >> d;
		D.insert({d, i});
	}

	vector<int> ans(q, -1);
	for(int i = 0; i < n; i++) {
		auto&[x,st] = XST[i];
		auto&[s,t] = st;
		auto itr = D.lower_bound({s,0});

		while(itr != D.end()) {
			if (itr->first >= t) break;
			ans[itr->second] = x;
			itr = D.erase(itr);
		}
	}

	for(int i = 0; i < q; i++) {
		cout << ans[i] << endl;
	}
}

int main() {
	task();
	return 0;
}