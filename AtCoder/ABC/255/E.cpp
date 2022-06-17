#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
using ll = long long;
void task() {
	int n,m;
	cin >> n >> m;

	vector<int> s(n - 1);
	vector<int> x(m);
	unordered_map<ll, int> freq;

	for(int i = 0; i < n - 1; i++) cin >> s[i];
	for(int i = 0; i < m; i++) cin >> x[i];

	ll prev = 0;
	int sign = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			freq[(x[j] - prev) * sign]++;
		}

		if (i < n - 1) {
			prev = s[i] - prev;
			sign = -sign;
		}
	}

	int ans = 0;
	for(auto [key, val] : freq) {
		ans = max(ans, val);
	}

	cout << ans << endl;
}

int main() {
	task();
	return 0;
}