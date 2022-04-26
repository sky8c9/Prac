#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int MOD = 998244353;

void task() {
	int n;
	cin >> n;

	vector<int> f(n + 1);
	f[1] = 1;f[2] = 3;
	for(int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
		f[i] %= MOD;
	}

	ll ans = 1;
	vector<int> next(n + 1);
	vector<int> seen(n + 1);
	vector<int> p(n + 1);
	vector<int> q(n + 1);
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= n; i++) {
		cin >> q[i];
		next[p[i]] = q[i];
	}

	for(int i = 1; i <= n; i++) {
		if (seen[p[i]]) continue;

		int cur = p[i];
		int cnt = 0;
		while(!seen[cur]) {
			seen[cur] = true;
			cnt++;
			cur = next[cur];
		}

		ans *= f[cnt];
		ans %= MOD;
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}